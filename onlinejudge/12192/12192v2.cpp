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

vll plot[MAX];
ll N, M, Q, LB, UB;
ll 

ll quad(ll x1, ll y1, ll x2, ll y2) {
    return min(abs(x1 - x2) + 1, abs(y1 - y2) + 1);
}

int main() {
    while (1) {
        cin >> N >> M;
        if (N == 0 && M == 0) break;
        for (ll i = 0; i < MAX; i++) plot[i].clear();
        for (ll i = 0; i < N; i++) {
            for (ll j = 0; j < M; j++) {
                ll tmp;
                cin >> tmp;
                plot[i].push_back(tmp); 
            }
        }
        cin >> Q;

        for (ll k = 0; k < Q; k++) {
            ll ans = 0, x1, x2;
            cin >> LB >> UB;
            for (ll y1 = 0; y1 < N; y1++) {
                auto it_x1 = lower_bound(plot[y1].begin(), plot[y1].end(), LB);
                x1 = distance(plot[y1].begin(), it_x1);
                for (ll y2 = y1; y2 < N; y2++) {
                    auto it_x2 = prev(upper_bound(plot[y2].begin(), plot[y2].end(), UB));
                    x2 = distance(plot[y2].begin(), it_x2);
                    if (x2 < x1) continue;
                    ll can = quad(x1, y1, x2, y2);
                    if (can > ans) {
                        // cout << "x1=" << x1 << "\ty1=" << y1 << endl;
                        // cout << "x2=" << x2 << "\ty2=" << y2 << endl;
                        // cout << "ca=" << can << endl;
                        ans = can;
                    }
                }
            }
            cout << ans << endl;
        }
        cout << "-" << endl;
    }
    return 0;
}
