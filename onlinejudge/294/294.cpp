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

ll numberOfDivisors(ll n) {
    ll r = (ll) sqrt(n);
    ll a = 2;
    for (ll i = 2; i <= r; i++)
        if (n % i == 0) a += 2;
    if (r * r == n) a--;
    return a;
}

int main() {
    ll c;
    cin >> c;
    while(c-- > 0) {
        ll lo, hi;
        cin >> lo >> hi;
        ll n = -1, nd = 0;
        for (ll i = lo; i <= hi; i++) {
            ll nd1 = numberOfDivisors(i);
            if (nd1 > nd)
                n = i, nd = nd1;
        }
        cout << "Between " << lo << " and " << hi << ", " << n << " has a maximum of " << nd << " divisors." << endl;
    }
    return 0;
}

