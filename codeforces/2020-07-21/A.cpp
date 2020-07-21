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

ll T, N, M;
unordered_set<ll> ELEMS;

int main() {
    cin >> T;
    while (T-- > 0) {
        ELEMS.clear();
        cin >> N >> M;
        // cout << "N " << N << " M " << M << endl;
        for (ll i = 0; i < N; i++) {
            ll tmp;
            cin >> tmp;
            ELEMS.insert(tmp);
            // cout << "insert " << tmp << endl; 
        }
        bool no = 1;
        for (ll i = 0; i < M; i++) {
            ll tmp;
            cin >> tmp;
            // cout << "count " << tmp << endl;
            if (no && ELEMS.count(tmp)) {
                no = 0;
                cout << "YES" << endl;
                cout << "1 " << tmp << endl;
                // break;
            }
        }
        if (no) {
            cout << "NO" << endl;
        }
    }
    return 0;
}
