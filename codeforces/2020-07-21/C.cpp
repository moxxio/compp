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

ll T, N;
vll ops;
string A, B;

void flip(ll n) {
    ops.push_back(n + 1);
    // cout << n + 1 << " " << A << "->";
    for (ll i = 0; i <= n; i++) {
        A[i] = A[i] == '0' ? '1' : '0';
    }
    reverse(A.begin(), A.begin() + n + 1);
    // cout << A << endl;
}

int main() {
    cin >> T;
    while (T-- > 0) {
        ops.clear();
        cin >> N >> A >> B;
        // cout << "A " << A << endl;
        // cout << "B " << B << endl;
        for (ll i = N - 1; i >= 0; i--) {
            if (A[i] != B[i]) {
                if (A[0] == B[i]) {
                    flip(0);
                }
                flip(i);
            }
        }
        cout << ops.size() << " ";
        for (ll op : ops) {
            cout << op << " ";
        }
        cout << endl;
        // cout << "A " << A << endl;
        // cout << "B " << B << endl;
    }
    return 0;
}
