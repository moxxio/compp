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

ll b, n;

int main() {
    cin >> b >> n;
    vll f;

    ll n1 = n;
    while (n1 % 2 == 0) {
        f.push_back(2);
        n1 = n1 / 2;
    }
    for (ll d = 3; n1 != 1 && d < b; d += 2) {
        while (n1 % d == 0) {
            f.push_back(d);
            n1 = n1 / d;
        }
    }
    if (n1 != 1) {
        cout << "impossible" << endl;
        return 0;
    }

    return 0;
}
