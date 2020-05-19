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
constexpr ll MAXN = 606;

vll adj[MAXN];
vll w[MAXN];
ll dist[MAXN];
ll T[5];
ll n, k;

void dijkstra(ll s) {
    priority_queue<pll> q;
    for (ll i = 0; i < MAXN; i++) dist[i] = ooo;
    dist[s] = 0;
    pll ini(0, s); q.push(ini);
    while (q.size()) {
        ll d = -q.top().fst;
        ll x = q.top().snd;
        // cout << "d=" << d << ", x=" << x << endl;
        q.pop();
        if (dist[x] != d) continue;
        for (ll i = 0; i < adj[x].size(); i++) {
            ll nd = d + w[x][i];
            ll nx = adj[x][i];
            // if (nx == k) cout << "x=" << x << endl;
            if (nd >= dist[nx]) continue;
            pll next(-nd, nx);
            dist[nx] = nd;
            q.push(next);
        }
    }
}

int main() {
    while (cin >> n >> k) {
        for (ll i = 0; i < MAXN; i++) {adj[i].clear(); w[i].clear();}
        for (ll i = 0; i < n; i++) cin >> T[i];
        for (ll i = 0; i < n; i++) {
            string line;
            getline(cin, line);
            if (line == "") getline(cin, line);
            stringstream stream(line);
            ll f, f1, f2 = -1, offset = (i+1) * 100;
            while (stream >> f) {
                // cout << "f=" << f << endl;
                f1 = f + offset;
                if (f2 != -1) {
                    ll dur = abs(f1 - f2) * T[i];
                    adj[f1].push_back(f2);
                    w[f1].push_back(dur);
                    // cout << f1 << " --(" << dur << ")--> " << f2 << endl;
                    adj[f2].push_back(f1);
                    w[f2].push_back(dur);
                    // cout << f2 << " --(" << dur << ")--> " << f1 << endl;
                }
                adj[f1].push_back(f);
                w[f1].push_back(0);
                // cout << f1 << " --(0)--> " << f << endl;
                adj[f].push_back(f1);
                w[f].push_back(60);
                // cout << f + 500 << " --(60)--> " << f1 << endl;
                if (f == 0) {
                    adj[600].push_back(f1);
                    w[600].push_back(0);
                    // cout << "600 --(0)--> " << f1 << endl;
                }
                f2 = f1;
            }
        }
        // cout << "hello" << endl;
        dijkstra(600);
        if (dist[k] == ooo) cout << "IMPOSSIBLE" << endl;
        else cout << dist[k] << endl;
    }
    return 0;
}
