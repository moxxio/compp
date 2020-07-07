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
constexpr ll MAX = 101;
constexpr ll MAX10 = 1111;
constexpr ll MAX2 = 202;

ld fav[MAX];
ll pri[MAX];
ll N, N1, N12, X, T, K;
ld dp[MAX2][MAX][MAX10]; // durchschnitt fav
ll co[MAX2][MAX][MAX10]; // kosten

ld hungry() {
    // randfall
    ll money = X * N1;
    ll teeUp = T * N1;
    if (teeUp >= money) return 0;

    // init
    for (ll j = 0; j <= N12; j++) {
        for (ll k = 0; k <= money; k++) {
            dp[0][j][k] = 0;
            co[0][j][k] = teeUp;
        }
    }

    // dp
    ll K2 = 2*K;
    for (ll i = 1; i <= K2; i++) {
        ll i1 = i - 1;
        for (ll j = 0; j <= N12; j++) {
            ll j1 = j - 1;
            for (ll k = 0; k <= money; k++) {
                // i nicht mitnehmen, j dishes, k geld
                ld can0 = dp[i1][j][k];
                ll pri0 = co[i1][j][k];

                // i mitnehmen, j-1 dishes, k-pri geld
                ld can1 = -1;
                ll pri1 = ooo;
                ll k1 = k - pri[i1 / 2];
                if (j1 >= 0 && k1 >= 0) {
                    can1 = dp[i1][j1][k1] + fav[i1 / 2];
                    pri1 = co[i1][j1][k1] + pri[i1 / 2];
                }

                // maximum bestimmen
                if (can0 > can1) {
                    dp[i][j][k] = can0;
                    co[i][j][k] = pri0;
                } else if (can0 == can1) {
                    dp[i][j][k] = can0;
                    co[i][j][k] = min(pri0, pri1);
                } else {
                    dp[i][j][k] = can1;
                    co[i][j][k] = pri1;
                }
                // cout << "dp[" << i << "][" << j << "][" << k << "]=" << dp[i][j][k] << endl;
            }
        }
    }

    // max preis mit trinkgeld
    ll BEST = 0;
    for (ll k = 1; k <= money; k++) {
        ld c = (ld) co[K2][N12][k];
        ll cost = (ll) ceil(c * 1.1L);
        if (cost <= money) BEST = k;
    }

    // cout << "BEST=" << BEST << endl;
    return dp[K2][N12][BEST] / (ld) N1;
}

int main() {
    while (1) {
        cin >> N >> X >> T >> K;
        if (!(N | X | T | K)) break;
        N1 = N + 1;
        // cout << "N1=" << N1 << endl;
        N12 = 2*N1;
        // cout << "N12=" << N12 << endl;

        for (ll i = 0; i < K; i++) {
            fav[i] = 0;
            cin >> pri[i];
            // pri[i] = pri[i] * 1.1L;
            for (ll j = 0; j < N1; j++) {
                ld tmp;
                cin >> tmp;
                fav[i] += tmp;
            }
            // fav[i] = fav[i] / N1;
            // cout << "fav[" << i << "]=" << fav[i] << endl;
        }

        cout << fixed << setprecision(2) << hungry() << endl;
    }
    return 0;
}
