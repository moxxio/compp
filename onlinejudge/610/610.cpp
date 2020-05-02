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
constexpr ll MAXN = 1010;

vll adj[MAXN];
ll low[MAXN]; ll num[MAXN];
ll curnum = 0;
bool use[MAXN][MAXN];

vector<pll> bridges;
vector<pll> diedges;

void find_bridges(int u, int p) {
    low[u] = num[u] = curnum++;
    for (ll v : adj[u]) {
        if (v == p) continue;
        if (num[v] == -1) { // forward edge or bridge
            find_bridges(v, u);
            low[u] = min(low[u], low[v]);
        } else { // backward edge
            low[u] = min(low[u], num[v]);
        }

        if (low[v] > num[u])
            bridges.push_back(make_pair(u, v));
        else if (!use[u][v]) {
            diedges.push_back(make_pair(u, v));
            use[u][v] = 1;
            use[v][u] = 1;
        }
    }
}

int main() {
    ll n, m;
    ll cnt = 1;
    while(1) {
        cin >> n >> m;
        // cout << "n=" << n << "; m=" << m << endl;
        if (n == 0 && m == 0) break;

        for (ll i = 0; i < n; i++) adj[i].clear();
        memset(low, 0, sizeof(low));
        memset(num, 0, sizeof(num));
        curnum = 0;
        memset(use, 0, sizeof(use));
        bridges.clear();
        diedges.clear();

        for (ll i = 0; i < m; i++) {
            ll x, y;
            cin >> x >> y;
            // cout << "x=" << x << "; y=" << y << endl;
            x--; y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        for (ll i = 0; i < n; i++) num[i] = -1;
        for (ll i = 0; i < n; i++) if (num[i] == -1)
            find_bridges(i, -1);

        cout << cnt++ << endl << endl;
        // cout << "bridges: " << bridges.size() << endl;
        // cout << "diedges: " << diedges.size() << endl;
        for (pll bridge : bridges) {
            cout << bridge.fst + 1 << " " << bridge.snd + 1 << endl;
            cout << bridge.snd + 1 << " " << bridge.fst + 1 << endl;
        }
        for (pll diedge : diedges) {
            cout << diedge.fst + 1 << " " << diedge.snd + 1 << endl;
        }
        cout << "#" << endl;
    }
    return 0;
}

