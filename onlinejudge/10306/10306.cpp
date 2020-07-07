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
constexpr ll MAXS = 303;

ll dp[MAXS][MAXS];
vector<pll> bitcoins;
ll N, M, S;

ll l2norm2(ll x, ll y) {
    return x*x + y*y;
}

ll l2norm(ll x, ll y) {
    return (ll) sqrt(l2norm2(x ,y));
}

ll square(ll x) {
    return x*x;
}

ll solve() {
    vector<pll> new_pos;
    new_pos.push_back(make_pair(0, 0));

    while (new_pos.size()) {
        vector<pll> pos = new_pos;
        new_pos.clear();

        for (pll p : pos) {
            ll xp = p.fst, yp = p.snd;

            for (pll c : bitcoins) {
                ll xc = c.fst, yc = c.snd;
                ll x = xp + xc, y = yp + yc;
                // cout << "x=" << x << ", y=" << y << endl;
                if (x > S || y > S) continue;
                if (dp[x][y] != -1) continue;

                dp[x][y] = dp[xp][yp] + 1;
                if (l2norm(x, y) == S && square(l2norm(x, y)) == l2norm2(x, y)) return dp[x][y];
                new_pos.push_back(make_pair(x, y));
            }
        }
    }
    return -1;
}

int main() {
    cin >> N;
    while (N-- > 0) {
        bitcoins.clear();
        for (ll i = 0; i < MAXS; i++) for (ll j = 0; j < MAXS; j++) dp[i][j] = -1;
        dp[0][0] = 0;

        cin >> M >> S;
        for (ll i = 0; i < M; i++) {
            ll e, f;
            cin >> e >> f;
            bitcoins.push_back(make_pair(e, f));
        }

        ll ans = solve();
        cout << (ans != -1 ? to_string(ans) : string("not possible")) << endl;
    }
    return 0;
}
