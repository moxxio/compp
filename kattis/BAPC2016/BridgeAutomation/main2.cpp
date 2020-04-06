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

ll dp[4040][4040];

int main() {
    cin >> n;
    vll arrival(n);
    for (ll& t : arrival) cin >> t;

    for (ll i = 0; i < arrival.size(); i++) dp[i][i] = 140;
    for (ll k = 1; i < arrival.size(); i++) {
        for (ll i = 0; k + i < arrival.size(); k++) {
            ll j = k + i;
            // ll t1 = dp[]
        }
    }

    return 0;
}
