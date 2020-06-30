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
constexpr ll MAX = 505;

ll plot[MAX][MAX];
ll N, M, Q, LB, UB;

ll lower_bound() {
}

int main() {
    while (1) {
        cin >> N >> M;
        if (N == 0 && M == 0) break;
        for (ll i = 0; i < N; i++) for (ll j = 0; j < M; j++) {
            cin >> plot[i][j];
        }
        cin >> Q;

        for (ll k = 0; k < Q; k++) {
            ll x1 = -1, y1 = -1, x2 = -1, y2 = -1;
            cin >> LB >> UB;
            for (ll i = 0; i < N; i++) {

            }
        }
    }
    return 0;
}
