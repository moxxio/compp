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
constexpr ld eps = 1e-7;
constexpr ld PI = 2.0 * acos(0.0);

ll b, n;
unordered_map<ll, bool> prime;
map<ll, vll> factorisations;
vll factors;
bool flag = 1;

void print_arr(vll& arr) {
    for (ll x : arr) cout << x << " ";
    cout << endl;
}

bool less_than(vll& v1, vll& v2) {
    if (v1.size() < v2.size()) return 1;
    if (v1.size() > v2.size()) return 0;
    for (ll i = v1.size() - 1; i >= 0; i--) {
        if (v1[i] < v2[i]) return 1;
        if (v1[i] > v2[i]) return 0;
    }
    return 0;
}

ll construct_number() {
    ll tmp = 1;
    ll ans = 0;
    for (ll f : factors) {
        ans += tmp * f;
        tmp *= b;
    }
    return ans;
}

bool is_prime(ll n) {
    if (n == 2) return 1;
    if (n <= 1 || n % 2 == 0) return 0;
    ll r = (ll) sqrt(n);
    for (ll d = 3; d <= r; d += 2) if (n % d == 0) return 0;
    return 1;
}

void factorise(ll x, ll d, vll& f) {
    if (x == 1) {
        if (flag) {
            print_arr(f);
            factors = f;
            flag = 0;
        } else if (less_than(f, factors)) {
            print_arr(f);
            factors = f;
        }
    }
    if (!flag && !less_than(f, factors)) {
        // cout << "return 2" << endl;
        return;
    }
    while (d > 1 && x % d != 0) d--;
    // cout << "d=" << d << endl;
    if (d == 1) {
        // cout << "return 3" << endl;
        return;
    }

    auto it = prime.find(d);
    bool p;
    if (it == prime.end()) {
        p = is_prime(d);
        prime[d] = p;
    } else p = (*it).snd;

    if (!p) {
        factorise(x, d - 1, f);
        // cout << "here" << endl;
    }
    ll x1 = x;
    ll pushed = 0;
    do {
        x1 = x1 / d;
        f.push_back(d);
        factorise(x1, d - 1, f);
        pushed++;
    } while (x1 % d == 0);
    while (pushed) {
        f.pop_back();
        pushed--;
    }
}

int main() {
    cin >> b >> n;
    vll f;
    factorise(n, b - 1, f);
    // print_arr(factors);
    if (flag) {
        cout << "impossible" << endl;
    } else {
        ll ans = construct_number();
        cout << ans << endl;
    }
    return 0;
}
