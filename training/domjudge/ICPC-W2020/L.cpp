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

ll n;

int main() {
    cin >> n;
    ld avg = 0;
    for (ll i = 0; i < n; i++) {
        ld tmp;
        cin >> tmp;
        avg += ld(1)/tmp;
    }
    cout << setprecision(15) << ld(n) / avg << endl;
    return 0;
}
