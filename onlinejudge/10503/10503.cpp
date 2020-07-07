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

ll N, M;
vector<pll> dominos;
bool used[1010101]; // ! input size unknown
ll L, R;

bool solve(ll n, ll d) {
    // cout << "n=" << n << ", d=" << d << endl;
    if (n >= N) return d == R;
    for (ll i = 0; i < dominos.size(); i++) {
        pll p = dominos[i];
        if (!used[i] && p.fst == d) {
            used[i] = 1;
            if (solve(n + 1, p.snd)) return 1;
            used[i] = 0;
        }
        if (!used[i] && p.snd == d) {
            used[i] = 1;
            if (solve(n + 1, p.fst)) return 1;
            used[i] = 0;
        }
    }
    return 0;
}

int main() {
    while (1) {
        cin >> N;
        if (N == 0) break;
        dominos.clear();
        memset(used, 0, sizeof(used));

        ll tmp;
        cin >> M >> tmp >> L >> R >> tmp;
        // cout << "L=" << L << ", R=" << R << endl;
        for (ll i = 0; i < M; i++) {
            ll x, y;
            cin >> x >> y;
            // cout << "(" << x << ", " << y << ")" << endl;
            dominos.push_back(make_pair(x, y));
        }

        cout << (solve(0, L) ? "YES" : "NO") << endl;
    }
    return 0;
}
