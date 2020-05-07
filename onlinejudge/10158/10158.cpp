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
constexpr ll MAXN = 10101;

ll pa[2*MAXN];
ll n;

ll ufind(ll i) {
    if (i != pa[i]) pa[i] = ufind(pa[i]);
    return pa[i];
}

void uunion(ll i, ll j) {
    pa[ufind(i)] = ufind(j);
}

bool setFriends(ll x, ll y) {
    ll px = ufind(x);
    ll py = ufind(y);
    ll ex = ufind(n+x);
    ll ey = ufind(n+y);

    if (px == ey || py == ex)
        return 0;

    uunion(px, py);
    uunion(ex, ey);
    return 1;
}

bool setEnemies(ll x, ll y) {
    ll px = ufind(x);
    ll py = ufind(y);
    ll ex = ufind(n+x);
    ll ey = ufind(n+y);

    if (px == py || ex == ey)
        return 0;

    uunion(px, ey);
    uunion(py, ex);
    return 1;
}

bool areFriends(ll x, ll y) {
    return ufind(x) == ufind(y);
}

bool areEnemies(ll x, ll y) {
    return ufind(x) == ufind(n+y);
}

int main() {
    cin >> n;
    
    iota(pa, pa + (2*n), 0);
//    iota(pa + n, pa + (2*n), 0);
//    for (ll i = 0; i < n; i++)
//        cout << pa[i] << endl;
//    for (ll i = 0; i < n; i++)
//        cout << pa[i + n] << endl;
//    for (ll i = 0; i < 2*n; i++)
//        pa[i] = i;
    
    while (1) {
        ll c, x, y;
        cin >> c >> x >> y;
        if (c == 0 && x == 0 && y == 0)
            break;

        switch (c) {
            case 1:
                if (!setFriends(x, y))
                    cout << "-1" << endl;
                break;
            case 2:
                if (!setEnemies(x, y))
                    cout << "-1" << endl;
                break;
            case 3:
                cout << areFriends(x, y) << endl;
                break;
            case 4:
                cout << areEnemies(x, y) << endl;
                break;
        }
    }

    return 0;
}
