#include <bits/stdc++.h>
#define fst first
#define snd second

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<string> vs;

constexpr int oo = 0x3f3f3f3f;
constexpr ll ooo = 0x3f3f3f3f3f3f3f3fLL;
constexpr ld eps = 1e-9;
constexpr ld PI = 2.0 * acos(0.0);
constexpr ll MAXN = 111;

struct edge {
    ll to, cap, flow, oi;
};

vector<edge> e[MAXN];
ll aug[MAXN];
ll pa[MAXN];

void addEdge(ll u, ll v, ll capUV, ll capVU) {
    edge uv, vu;
    uv.to = v;
    uv.cap = capUV;
    uv.flow = 0;
    uv.oi = e[v].size();

    vu.to = u;
    vu.cap = capVU;
    vu.flow = 0;
    vu.oi = e[u].size();

    e[u].push_back(uv);
    e[v].push_back(vu);
}

bool findAugPathEK(ll src, ll sink, ll n) {
    static ll qu[MAXN];
    for (ll i = 0; i < n; i++) pa[i] = -1;
    aug[src] = ooo;

    ll start = 0, end = 0;
    qu[end++] = src;
    while (start != end) {
        ll u = qu[start++];
        for (ll i = 0; i < e[u].size(); i++) {
            ll v = e[u][i].to;
            ll curaug = e[u][i].cap - e[u][i].flow;
            if (pa[v] == -1 && curaug > 0) {
                qu[end++] = v;
                aug[v] = min(aug[u], curaug);
                pa[v] = e[u][i].oi;
                if (v == sink) return true;
            }
        }
    }
    return false;
}

ll calcMaxFlow(ll src, ll sink, ll n) {
    ll ret = 0;
    for (ll i = 0; i < n; i++) for (ll j = 0; j < e[i].size(); j++) e[i][j].flow = 0;
    while (findAugPathEK(src, sink, n)) {
        ll v = sink;
        while (v != src) {
            e[e[v][pa[v]].to][e[v][pa[v]].oi].flow += aug[sink];
            e[v][pa[v]].flow -= aug[sink];
            v = e[v][pa[v]].to;
        }
        ret += aug[sink];
        if (ret >= ooo) break;
    }
    return ret;
}

int main() {
    ll n;
    ll counter = 1;
    while (true) {
        cin >> n;
        if (n == 0) break;
        for (ll i = 0; i < n; i++) e[i].clear();

        ll s, t, c;
        cin >> s >> t >> c;
        s--; t--;

        while (c-- > 0) {
            ll x, y, b;
            cin >> x >> y >> b;
            x--; y--;
            addEdge(x, y, b, b);
        }

        cout << "Network " << counter++ << endl;
        cout << "The bandwidth is " << calcMaxFlow(s, t, n) << "." << endl << endl;
    }
    return 0;
}
