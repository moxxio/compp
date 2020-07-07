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
constexpr ll MAXN = 77;

ll T[MAXN][MAXN];
ll C, N, N1;

ll query(ll x1, ll y1, ll x2, ll y2) {
    if (x1 <= x2 && y1 <= y2) {
        return T[x2][y2] - T[x2][y1] - T[x1][y2] + T[x1][y1];
    } else if (x1 > x2 && y1 <= y2) {
        return T[N1][y2] - T[x1][y2] - T[N1][y1] + T[x1][y1] + T[x2][y2] - T[x2][y1];
    } else if (x1 <= x2 && y1 > y2) {
    
    } else {

    }
}

int main() {
    cin >> C;
    while (C-- > 0) {
        cin >> N;
        N1 = N - 1;
        memset(S, 0, sizeof(S));
        for (ll i = 0; i < N; i++) for (ll j = 0; j < N; j++) cin >> T[i][j];
        

        ll ans = -ooo;
        for (ll k = 0; k < N; k++) for (ll a = 0; a < N; a++) for (ll b = 0; b < N; b++) {
            ll i = (a + k) % N;
        }
    }
    return 0;
}
