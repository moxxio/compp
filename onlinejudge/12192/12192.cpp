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

ll row_lower_bound(ll i) {
    ll lo = 0, hi = M - 1;
    while (lo < hi) {
        ll mi = (lo + hi) / 2;
        if (plot[i][mi] >= LB) lo = mi;
        else hi = mi - 1;
    }
    return lo;
}

ll row_upper_bound(ll i) {
    ll lo = 0, hi = M - 1;
    while (lo < hi) {
        ll mi = (lo + hi) / 2;
        if (plot[i][mi] <= UB) lo = mi;
        else hi = mi - 1;
    }
    return lo;
}

ll col_lower_bound(ll j) {
    ll lo = 0, hi = M - 1;
    while (lo < hi) {
        ll mi = (lo + hi) / 2;
        if (plot[mi][j] >= LB) lo = mi;
        else hi = mi - 1;
    }
    return lo;
}

ll col_upper_bound(ll j) {
    ll lo = 0, hi = M - 1;
    while (lo < hi) {
        ll mi = (lo + hi) / 2;
        if (plot[mi][j] <= UB) lo = mi;
        else hi = mi - 1;
    }
    return lo;
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
            ll ans = 0, x1, y1, x2, y2;
            cin >> LB >> UB;
            for (ll i = 0; i < N; i++) {
                x1 = row_lower_bound(
            }
        }
    }
    return 0;
}
