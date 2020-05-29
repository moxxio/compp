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
constexpr ll MAXN = 101;

ll N, A[MAXN], R;
ld B, V, E, F;
ld mem[10101], dp[MAXN];

ld timeAB(ll a, ll b) {
    ll d = abs(A[b] - A[a]);
    return mem[d];
}

ld time(ld x) {
    if (x >= R) return 1./(V - E * (x-R));
    return 1./(V - F * (R-x));
}

int main() {
    while (1) {
        cin >> N;
        if (N == 0) break;
        for (ll i = 0; i < N; i++) cin >> A[i];
        cin >> B >> R >> V >> E >> F;

        mem[0] = 0;
        for (ll i = 1; i <= A[N-1]; i++) mem[i] = time(i-1) + mem[i-1];

        dp[0] = 0;
        for (ll i = 1; i < N; i++) {
            dp[i] = timeAB(0, i); // + dp[0]
            for (ll j = 1; j < i; j++) {
                dp[i] = min(dp[i], dp[j] + timeAB(j, i) + B);
            }
        } 
        cout << fixed << setprecision(4) << dp[N-1] << endl;
    }
    return 0;
}
