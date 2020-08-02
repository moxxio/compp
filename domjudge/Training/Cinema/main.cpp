#include <bits/stdc++.h>
#define fst first
#define snd second

using namespace std;
typedef long long ll;
// typedef __int128 lll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<string> vs;

constexpr int oo = 0x3f3f3f3f;
constexpr ll ooo = 0x3f3f3f3f3f3f3f3fLL;
constexpr ld eps = 1e-9;
constexpr ld PI = 2.0 * acos(0.0);
constexpr ll MAX = 303;

ll T, N, M;
vll adj[MAX]; // input
ll p, v[MAX]; // temp (node color)
ll fg; // output (cycle found 0/1)
ll od[MAX]; // output (order)
unordered_map<ll, ll> m1, m2;

void dfs(ll a) {
    if (v[a] == 1) fg = 1;
    if (v[a]) return;
    v[a] = 1;
    for (ll i = 0; i < adj[a].size(); i++) dfs(adj[a][i]);
    v[a] = 2;
    od[p] = a;
    p--;
}

void topsort(ll n) {
    memset(v, 0, sizeof(v));
    fg = 0; p = n - 1;
    for (ll i = 0; i < n; i++) if (!v[i]) dfs(i);
}

int main() {
    cin >> T;
    ll t = 1;
    while (T-- > 0) {
        cin >> N;
        for (ll i = 0; i < MAX; i++) adj[i].clear();
        for (ll i = 0; i < N; i++) {
            cin >> M;
            ll x1 = 0, x2 = 0;
            for (ll j = 0; j < M; j++) {
                x2 = x1;
                cin >> x1;
                if (!m1.count(x1)) {
                    ll tmp = m1.size();
                    m1[x1] = tmp;
                    m2[tmp] = x1;
                }
                if (j > 0) adj[m1[x2]].push_back(m1[x1]);
            }
        }

        topsort(m1.size());
        cout << "Case #" << t++ << ": ";
        if (fg == 1) cout << "impossible";
        else for (ll i = 0; i < m1.size(); i++) cout << m2[od[i]] << " ";
        cout << endl;
    }
    return 0;
}
