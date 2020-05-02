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
constexpr MAXN = 10101;

ll pa[MAXN]; // partner
ll en[MAXN]; // enemies

ll ufind(ll* ar, ll i) {
    if (ar[i] != i) ar[i] = ufind(ar, ar[i]);
    return ar[i];
}

void uunion(ll* ar, ll a, ll b) {
    ar[ufind(a)] = ufind(b);
}

bool setFriends(ll x, ll y) {
    
}

bool setEnemies(ll x, ll y) {
    return 1;
}

bool areFriends(ll x, ll y) {
    return 0;
}

bool areEnemies(ll x, ll y) {
    return 0;
}

int main() {
    ll n;
    cin >> n;
    
    iota(pa, pa + n, 0);
    iota(en, en + n, 0);

    while (1) {
        ll c, x, y;
        cin >> c >> x >> y;
        if (c == 0 && x == 0 && y == 0) break;
        switch (c) {
            case 1:
            break;
            case 2:
            break;
            case 3:
            break;
            case 4:
            break;
        }
    }
    return 0;
}
