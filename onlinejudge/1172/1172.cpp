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

unordered_map<string, ll> type2num;
ll type[2*MAXN];
ll vals[2*MAXN];
ll dp1[MAXN][MAXN]; // eco value
ll dp2[MAXN][MAXN]; // num bridges

int main() {
    ll T, N;
    cin >> T;
    while (T-- > 0) {
        type2num.clear();
        memset(type, 0, sizeof(type));
        memset(vals, 0, sizeof(vals));
        memset(dp1, 0, sizeof(dp1));
        memset(dp2, 0, sizeof(dp2));

        string n, t; ll v, n0 = 0, n1, n2;
        for (ll z = 0; z < 2; z++) {
           cin >> N;
           for (ll i = 0; i < N; i++) {
                cin >> n >> t >> v;
                if (type2num.count(t) == 0) type2num[t] = type2num.size();
                type[n0] = type2num[t];
                vals[n0] = v;
                n0++;
            }
            if (z == 0) n1 = n0;
            else n2 = n0 - n1;
        }

        for (ll i = 1; i <= n1; i++) for (ll j = 1; j <= n2; j++) {
            ll k = i - 1;
            ll l = j + n1 - 1;
            dp1[i][j] = max(dp1[i-1][j], dp1[i][j-1]);
            if (dp1[i-1][j] > dp1[i][j-1]) dp2[i][j] = dp2[i-1][j];
            else if (dp1[i-1][j] < dp1[i][j-1]) dp2[i][j] = dp2[i][j-1];
            else dp2[i][j] = min(dp2[i-1][j], dp2[i][j-1]);
            if (type[k] == type[l] && dp1[i][j] < dp1[i-1][j-1] + vals[k] + vals[l]) {
                dp1[i][j] = dp1[i-1][j-1] + vals[k] + vals[l];
                dp2[i][j] = dp2[i-1][j-1] + 1;
            }
        }

        cout << dp1[n1][n2] << " " << dp2[n1][n2] << endl;
    }
    return 0;
}

