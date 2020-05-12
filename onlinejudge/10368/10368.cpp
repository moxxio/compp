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

ll x1;
ll x2;

ll ggt(ll a, ll b) {
    for (x2 = 0; b != 0; x2++) {
        ll tmp = a % b;
        if (a / b > 1 && x1 == -1)
            x1 = x2;
        a = b;
        b = tmp;
    }
    return a;
}

int main() {
    ll a, b;
    while (1) {
        cin >> a >> b;
        if (a == 0 && b == 0)
            break;
        if (a < b)
            swap(a, b);
        x1 = -1;
        ggt(a, b);
        cout << (x1 == -1 ? (x2 % 2 == 1 ? "Stan wins" : "Ollie wins") : (x1 % 2 == 0 ? "Stan wins" : "Ollie wins")) << endl;
    }
    return 0;
}

