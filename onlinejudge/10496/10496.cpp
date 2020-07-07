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
constexpr ll MAXN = 11;

ll r[MAXN][MAXN];
ll dp[1 << MAXN][MAXN];

ll play(ll n, ll S, ll s) {
    if (S == (1 << s)) return r[s][0];
    ll& v = dp[S][s];
    if (v >= 0) return v;
    v = oo;
    for (ll i = 0; i < n; i++) if (i != s) if (S & (1 << i))
        v = min(v, r[s][i] + play(n, S - (1 << s), i));
    return v;
}

ll tsp(ll n) {
    memset(dp, -1, sizeof(dp));
    return play(n, (1 << n) - 1, 0);
}

ll l1norm(ll x1, ll y1, ll x2, ll y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
    ll N;
    cin >> N;
    while (N-- > 0) {
        for (ll i = 0; i < MAXN; i++) for (ll j = 0; j < MAXN; j++) r[i][j] = oo;
        ll X, Y, XK, YK, M;
        cin >> X >> Y >> XK >> YK >> M;
        vector<pll> nodes;
        nodes.push_back(make_pair(XK, YK));
        for (ll i = 0; i < M; i++) {
            ll XB, YB;
            cin >> XB >> YB;
            for (ll j = 0; j < nodes.size(); j++) {
                ll x = nodes[j].fst, y = nodes[j].snd;
                ll w = l1norm(x, y, XB, YB);
                r[i+1][j] = w, r[j][i+1] = w;
            }
            nodes.push_back(make_pair(XB, YB));
        }
        cout << "The shortest path has length " << tsp(M+1) << endl;
    }
    return 0;
}
