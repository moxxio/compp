#include <bits/stdc++.h>
#define fst first
#define snd second

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<string> vs;

constexpr int oo = 0x3f3f3f3f;
constexpr ll ooo = 0x3f3f3f3f3f3f3f3fLL;
constexpr double eps = 1e-7;
constexpr double PI = 2.0 * acos(0.0);

ll n;

int main() {
    cin >> n;
    vll sticks(n);
    for (ll& x : sticks) cin >> x;
    sort(sticks.begin(), sticks.end());
    for (ll i = 0; i + 2 < sticks.size(); i++) {
        ll i1 = i + 1;
        ll i2 = i1 + 1;
        if (sticks[i] + sticks[i1] > sticks[i2]
            && sticks[i1] + sticks[i2] > sticks[i]
            && sticks[i2] + sticks[i] > sticks[i1]) {
                cout << "possible" << endl;
                return 0;
            }
    }
    cout << "impossible" << endl;
    return 0;
}
