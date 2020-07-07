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
constexpr ll MAXN = 20;
constexpr ll BIG_MAXN = 1 << 20;

ll N, M;
ld dp[MAXN][BIG_MAXN];
ld T[MAXN][MAXN];

int main() {
    while (1) {
        cin >> N >> M;
        if (N == 0 && M == 0) break;
        for (ll i = 0; i < MAXN; i++) for (ll j = 0; j < 1 << BIG_MAXN; j++) dp[i][j] = 0;
        for (ll i = 0; i < N; i++) for (ll j = 0; j < M; j++) cin >> T[i][j];
    }
    return 0;
}

