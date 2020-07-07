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
constexpr ll MAXN = 50;

typedef ld weight;
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

weight cost[MAXN][MAXN];
weight d[MAXN];

bool findAugPathMinCost(ll src, ll sink, ll n) {
    for (ll i = 0; i < n; i++) d[i] = oo;
    d[src] = 0;
    aug[src] = oo;

    for (ll k = 0; k < n; k++) for (ll u = 0; u < n; u++) if (d[u] < oo) for (ll i = 0; i < e[u].size(); i++) {
        ll v = e[u][i].to;
        ll curaug = e[u][i].flow < 0 ? -e[u][i].flow : e[u][i].cap - e[u][i].flow;
        ll curcost = e[u][i].flow < 0 ? -cost[v][u] : cost[u][v];
        if (curaug > 0 && d[v] > d[u] + curcost) {
            d[v] = d[u] + curcost;
            aug[v] = min(aug[u], curaug);
            pa[v] = e[u][i].oi;
        }
    }
    return d[sink] < oo;
}

ll pi[MAXN];

bool findAugPathDijkstra(ll src, ll sink, ll n) {
    priority_queue<pair<weight, ll>> h;

    for (ll i = 0; i < n; i++) d[i] = oo;
    d[src] = 0;
    aug[src] = oo;

    h.push(make_pair(-d[src], src));
    while (!h.empty()) {
        ll u = h.top().snd;
        weight dst = -h.top().fst;
        h.pop();

        if (d[u] != dst) continue;

        for (ll i = 0; i < e[u].size(); i++) {
            ll v = e[u][i].to;
            ll curaug = e[u][i].flow < 0 ? -e[u][i].flow : e[u][i].cap - e[u][i].flow;
            ll curcost = e[u][i].flow < 0 ? -cost[v][u] - pi[v] + pi[u] : cost[u][v] + pi[u] - pi[v];
            if (curaug > 0 && dst + curcost < d[v]) {
                d[v] = dst + curcost;
                aug[v] = min(aug[u], curaug);
                pa[v] = e[u][i].oi;
                h.push(make_pair(-d[v], v));
            }
        }
    }
    return d[sink] < oo;
}

ll calcMaxFlow(ll src, ll sink, ll n) {
    ll ret = 0;
    for (ll i = 0; i < n; i++) for (ll j = 0; j < e[i].size(); j++) e[i][j].flow = 0;

    for (ll i = 0; i < n; i++) pi[i] = 0;
    findAugPathMinCost(src, sink, n);
    for (ll i = 0; i < n; i++) if (d[i] < oo) pi[i] += d[i];

    while (findAugPathDijkstra(src, sink, n)) {
        for (ll i = 0; i < n; i++) if (d[i] < oo) pi[i] += d[i];
        ll v = sink;
        while (v != src) {
            e[e[v][pa[v]].to][e[v][pa[v]].oi].flow += aug[sink];
            e[v][pa[v]].flow -= aug[sink];
            v = e[v][pa[v]].to;
        }
        ret += aug[sink];
        if (ret >= oo) break;
    }
    return ret;
}

ll N, M;

int main() {
    while (1) {
        cin >> N >> M;
        ll NM = N + M;
        if (N == 0 && M == 0) break;
        for (ll i = 0; i < MAXN; i++) {
            e[i].clear();
            for (ll j = 0; j < MAXN; j++) cost[i][j] = 0;
        }

        for (ll i = 0; i < N; i++) addEdge(NM, i, 1, 0);
        for (ll i = 0; i < M; i++) addEdge(i + N, NM + 1, 1, 0);
        for (ll i = 0; i < N; i++) {
            for (ll j = 0; j < M; j++) {
                addEdge(i, j + N, 1, 0);
                cin >> cost[i][j + N];
            }
        }

        calcMaxFlow(NM, NM + 1, NM + 2);
        ld ans = 0;
        for (ll u = 0; u < N; u++) {
            for (ll i = 0; i < e[u].size(); i++) {
                ll v = e[u][i].to;
                if (e[u][i].flow == 1) ans += cost[u][v];
            }
        }
        cout << fixed << setprecision(2) << ans / (ld) N << endl;
    }
    return 0;
}
