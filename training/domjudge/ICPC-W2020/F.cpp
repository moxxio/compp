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



int main() {
    ll n, k;
    cin >> n >> k;
    k--;
    for (ll i = 0; i < n; i++) {
        ll tmp;
        cin >> tmp;
        k += tmp;
    }
    cout << min(n, k) << endl;
    return 0;
}
