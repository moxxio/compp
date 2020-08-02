#include <bits/stdc++.h>
#define fst first
#define snd second

using namespace std;
typedef long long ll;
// typedef __int128 lll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<string> vs;

constexpr int oo = 0x3f3f3f3f;
constexpr ll ooo = 0x3f3f3f3f3f3f3f3fLL;
constexpr ld eps = 1e-9;
constexpr ld PI = 2.0 * acos(0.0);

ll T, N, Y;

// ax + by = d
// returns d
ll extGcd(ll a, ll b, ll &x, ll &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1, rst;
    rst = extGcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return rst;
}

int main() {
    cin >> T;
    ll t = 1;
    while (T-- > 0) {
        cin >> N >> Y;
        ll a = 1, b = Y, x, y;

        for (ll i = 0; i < N; i++) a = 10 * a;
        ll d = extGcd(a, b, x, y);

        // cout << a << "*" << x << " + " << b << "*" << y << " = " << d << endl;
        cout << "Case #" << t++ << ": " << (y <= 0 ? y + a : y) << endl;
    }
    return 0;
}
