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
constexpr ll MAX = 2020;

ll T, N, N2;
vll W;
bool DP[2 * MAX][MAX]; // n x W

bool knapsack() {
    memset(DP, 0, sizeof(DP));
    for (ll i = 1; i <= W.size(); i++) {
        DP[i][0] = 1;
    } 
    for (ll i = 1; i <= W.size(); i++) {
        for (ll j = 1; j <= N; j++) {
            DP[i][j] = DP[i - 1][j];
            if (j >= W[i - 1]) {
                DP[i][j] = DP[i][j] || DP[i - 1][j - W[i - 1]];
            }
        }
    }
    return DP[W.size()][N];
}

int main() {
    cin >> T;
    while (T-- > 0) {
        // cout << "---" << endl;
        W.clear();

        cin >> N;
        N2 = 2 * N;
        ll high = 0, count = 0, next;
        for (ll i = 0; i < N2; i++) {
            cin >> next;
            if (next > high) {
                if (count > 0) {
                    W.push_back(count);
                }
                count = 0;
                high = next;
            }
            count++;
        }
        if (count > 0) {
            W.push_back(count);
        }

        // cout << "L" << endl;
        // for (ll i = 0; i < W.size(); i++) cout << L[i] << " ";
        // cout << endl;
        bool ok = knapsack();
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}
