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

ll turn(ll a, ll b, ll pm) {
    ll mxx = 0;
    if (b == 0)
        return pm;
    for (ll i = 1; i <= a / b; i++) {
        ll ap = b;
        ll bp = a - i*b;
        if (ap < bp)
            swap(ap, bp);

        ll can = turn(ap, bp, -pm);
        if (i == 1 || mxx < pm * can)
            mxx = can;
    }
    return mxx;
}

void minmax(ll a, ll b) {
    ll mxx = 0;
    for (ll i = 1; i <= a/b; i++) {
        ll ap = b;
        ll bp = a - i*b;
        if (ap < bp)
            swap(ap, bp);

        ll can = turn(ap, bp, -1);
        if (i == 1 || mxx < can)
            mxx = can;
    }
    if (mxx == 1)
        cout << "Stan wins" << endl;
    else
        cout << "Ollie wins"<< endl;
}

int main() {
    ll a, b;
    while (1) {
        cin >> a >> b;
        if (a == 0 && b == 0)
            break;

        if (a < b)
            swap(a, b);

        minmax(a, b);
    }
    return 0;
}

