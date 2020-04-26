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
constexpr ll MAXN = 1111;

vll adj[MAXN];
vll w[MAXN];
ll d[MAXN];

bool bellmanford(ll n, ll src) {
    for (ll i = 0; i < n; i++) d[i] = ooo;
    d[src] = 0;
    for (ll k = 0; k < n; k++) for (ll i = 0; i < n; i++)
        if (d[i] < ooo) for (ll j = 0; j < adj[i].size(); j++)
            d[adj[i][j]] = min(d[adj[i][j]], max(d[i] + w[i][j], -ooo));

    bool possible = 0;
    for (ll i = 0; i < n; i++) if (d[i] < ooo) for (ll j = 0; j < adj[i].size(); j++)
        if (d[adj[i][j]] > d[i] + w[i][j]) d[adj[i][j]] = -ooo, possible = 1;
    return possible;
}

int main() {
    ll c;
    cin >> c;
    while (c-- > 0) {
        ll n, m;
        cin >> n >> m;

        for (ll i = 0; i < n; i++) adj[i].clear();
        for (ll i = 0; i < n; i++) w[i].clear();

        while (m-- > 0) {
            ll x, y, t;
            cin >> x >> y >> t;
            adj[x].push_back(y);
            w[x].push_back(t);
        }

        if (bellmanford(n, 0)) cout << "possible" << endl;
        else cout << "not possible" << endl;
    }
    return 0;
}
