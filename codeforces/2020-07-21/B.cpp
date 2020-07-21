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
constexpr ll MAX = 1010;

ll T, N;

int main() {
    cin >> T;
    while (T-- > 0) {
        cin >> N;
        string ans = "";
        for (ll i = 0; i < N; i++) {
            ll tmp;
            cin >> tmp;
            // cout << "tmp " << tmp << endl;
            if (ans == "" && tmp > 1) {
                ans = i % 2 == 0 ? "First" : "Second";
                // cout << "i " << i << " winner " << ans << endl;
            }
        }
        if (ans == "") {
            cout << (N % 2 == 0 ? "Second" : "First") << endl;
        } else {
            cout << ans << endl;
        }
    }
    return 0;
}
