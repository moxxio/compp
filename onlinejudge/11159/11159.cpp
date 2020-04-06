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
constexpr ll MAXN = 222;

vll adj[MAXN];
bool matched[MAXN];
bool matchedEdge[MAXN][MAXN];
bool visited[MAXN];

bool dfs(ll node, bool backEdge, bool recursive) {
    if (visited[node]) return false;
    visited[node] = true;

    if (!matched[node] && !recursive) {
        matched[node] = true;
        return true;
    }

    for (ll nb : adj[node]) {
        if (matchedEdge[node][nb] == backEdge && dfs(nb, !backEdge, false)) {
            matchedEdge[node][nb] = !matchedEdge[node][nb];
            matchedEdge[nb][node] = !matchedEdge[nb][node];
            matched[node] = true;
            return true;
        }
    }

    return false;
}

ll match(ll n) {
    memset(matched, 0, sizeof(matched));
    memset(matchedEdge, 0, sizeof(matchedEdge));

    ll nMatched = 0;
    while (true) {
        bool foundMatch = false;
        for (ll i = 0; i < n; ++i) {
            if (matched[i]) continue;

            memset(visited, 0, sizeof(visited));
            bool ret = dfs(i, false, true);
            if (ret) {
                ++nMatched;
                foundMatch = true;
            }
        }
        if (!foundMatch) break;
    }

    return nMatched;
}

vll setA, setB;

int main() {
    ll t;
    cin >> t;
    ll c = 0;
    while (t-- > 0) {
        setA.clear(); setB.clear(); // clear everything
        for (ll i = 0; i < MAXN; i++) adj[i].clear();

        ll n, m; // read input
        cin >> n;
        for (ll i = 0; i < n; i++) {
            ll x; cin >> x; setA.push_back(x);
        }
        cin >> m;
        for (ll i = 0; i < m; i++) {
            ll x; cin >> x; setB.push_back(x);
        }

        // cout << "n " << n << " m " << m << endl;
        for (ll i = 0; i < n; i++) { // build bipartite graph
            for (ll j = 0; j < m; j++) {
                if (setB[j] % setA[i] == 0) {
                    // cout << setA[i] << " and " << setB[j] << endl;
                    adj[i].push_back(j + n);
                    adj[j + n].push_back(i);
                }
            }
        }

        c++; // solve and output
        cout << "Case " << c << ": " << match(n + m) << endl;
    }
    return 0;
}
