#include <bits/stdc++.h>
#define fst first
#define snd second

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef tuple<ll, ll, ll> ttt;

constexpr int oo = 0x3f3f3f3f;
constexpr ll ooo = 0x3f3f3f3f3f3f3f3fLL;
constexpr ld eps = 1e-7;
constexpr ld PI = 2.0 * acos(0.0);

ll n;

ll norm1(ll x1, ll y1, ll x2, ll y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
    cin >> n;
    vector<ttt> beacons(n);
    for (auto&[x, y, d] : beacons) cin >> x >> y >> d;

    for (ll i = 0; i + 1 < n; i++) {
        auto[x1, y1, d1] = beacons[i];
        auto[x2, y2, d2] = beacons[i + 1];

        ll d = norm1(x1, y1, x2, y2);
        if (d % 2 == 1 || d1 + d2 < d) continue;

        for (ll j = 0; j < 4; j++) {
            ll sgn1 = j % 2 == 0 ? 1 : -1;
            ll sgn2 = (j / 2) % 2 == 0 ? 1 : -1;

            for (ll k = 0; k <= d1; k++) {
                ll x = x1 + sgn1 * k;
                ll y = y1 + sgn2 * (d2 - k);
                pll xy = make_pair(x, y);
                
                if (norm1(x, y, x2, y2) == d2) {

                }
            }
        }
    }

    return 0;
}
