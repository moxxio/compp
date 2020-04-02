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
typedef tuple<ll, ll, ll, ll> line;

constexpr int oo = 0x3f3f3f3f;
constexpr ll ooo = 0x3f3f3f3f3f3f3f3fLL;
constexpr ld eps = 1e-7;
constexpr ld PI = 2.0 * acos(0.0);

ll n;

bool colinear(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    return x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2) == 0;
}

ll norm1(ll x1, ll y1, ll x2, ll y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

line intersect(line l1, line l2) {
    auto[x11, y11, x12, y12] = l1;
    auto[x21, y21, x22, y22] = l2;

    if (colinear(x11, y11, x12, y12, x21, y21) && colinear(x11, y11, x12, y12, x22, y22)) {
        if (x11 < x12 && y11 < y12) {
            if ()
        }
        if (x11 < x12 && y11 < y12) {

        }
        if (x11 < x12 && y11 < y12) {

        }
        if (x11 < x12 && y11 < y12) {

        }
    }
}

int main() {
    cin >> n;
    vector<ttt> beacons(n);
    for (auto&[x, y, d] : beacons) cin >> x >> y >> d;

    for (ll i = 0; i + 1 < n; i++) {
        auto[x1, y1, d1] = beacons[i];
        auto[x2, y2, d2] = beacons[i + 1];

        ll d = norm1(x1, y1, x2, y2);
        if (d % 2 == 1 || d1 + d2 < d) {
            // TODO
            continue;
        }
    }

    return 0;
}
