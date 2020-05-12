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

vll num;

ll gcd(ll a, ll b) {
    ll h;
    if (a == 0) return abs(b);
    if (b == 0) return abs(a);
    do {
        h = a % b;
        a = b;
        b = h;
    } while (b != 0);
    return abs(a);
}

int main() {
    while (1) {
        num.clear();
        while (1) {
            ll n;
            cin >> n;
            if (n == 0)
                break;
            num.push_back(n);
        }
        if (num.size() == 0)
            break;
        ll ans = abs(num[0] - num[1]);
        for (ll i = 1; i + 1 < num.size(); i++) {
            ans = gcd(ans, num[i] - num[i+1]);
        }
        cout << ans << endl;
    } 
    return 0;
}
