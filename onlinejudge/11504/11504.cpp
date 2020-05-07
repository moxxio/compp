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
constexpr ll MAXN = 101010;

vll adj[MAXN][2];
ll ccomp, comp[MAXN];
vll st;

void dfs(ll n, ll c, ll dir) {
    if (comp[n] != -1) return;
    comp[n] = c;
    for (ll i = 0; i < adj[n][dir].size(); i++)
        dfs(adj[n][dir][i], c, dir);
    st.push_back(n);
}

void kosaraju(ll n) {
    memset(comp, -1, sizeof(comp));
    st.clear();
    for (ll i = 0; i < n; i++) dfs(i, 0, 0);
    reverse(st.begin(), st.end());
    memset(comp, -1, sizeof(comp));
    ccomp = 0;
    for (ll i = 0; i < n; i++)
        if (comp[st[i]] == -1) dfs(st[i], ccomp++, 1);
}

int main() {
    ll c, n, m, u, v;
    cin >> c;
    while (c-- > 0) {
        cin >> n >> m;

        for (ll i = 0; i < n; i++) {
            adj[i][0].clear();
            adj[i][1].clear();
        }

        while (m-- > 0) {
            cin >> u >> v;
            u--; v--;
            adj[u][0].push_back(v);
            adj[v][1].push_back(u);
        }

        kosaraju(n);
        // cout << "ccomp=" << ccomp << endl;

        ll mnn = 0;
        vll pred(ccomp, -1);
        for (ll x = 0; x < n; x++)
            for (ll y : adj[x][0])
                if (comp[x] != comp[y])
                    pred[comp[y]] = comp[x];
        for (ll p : pred)
            if (p == -1)
                mnn++;
        cout << mnn << endl;
    }
    return 0;
}

