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

vll adj[MAXN];
vll w[MAXN];
ll d[MAXN];

void bellmanford(ll n, ll src) {
    for (ll i = 0; i < n; i++) d[i] = ooo;
    d[src] = 0;
    for (ll k = 0; k < n; k++) for (ll i = 0; i < n; i++)
        if (d[i] < ooo) for (ll j = 0; j < adj[i].size(); j++)
            d[adj[i][j]] = min(d[adj[i][j]], max(d[i] + w[i][j], -ooo));
}

int main() {
    ll c, n, e, t, m;
    cin >> c;
    while (c-- > 0) {
        cin >> n >> e >> t >> m;
        e--;

        for (ll i = 0; i < MAXN; i++) adj[i].clear();
        for (ll i = 0; i < MAXN; i++) w[i].clear();

        while (m-- > 0) {
            ll a, b, c;
            cin >> a >> b >> c;
            a--; b--;
            adj[b].push_back(a);
            w[b].push_back(c);
        }

        bellmanford(n, e);

        ll mice = 0;
        for (ll i = 0; i < n; i++) {
            if (d[i] <= t) mice++;
        }
        cout << mice << endl;
        if (c > 0) cout << endl;
    }
    return 0;
}

