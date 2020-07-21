#include <bits/stdc++.h>
#define fst first
#define snd second

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef unsigned long long ull;
typedef double ld;
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
ld T[MAXN][MAXN];
pair<ull, ld> DP[BIG_MAXN];

bool testBit(ull v, ull b) {
    return (v >> b) & 1;
}

ull nextBitperm(ull v) {
    ull l1 = 1;
    ull t = v | (v - l1);
    return (t + l1) | (((~t & -~t) - l1) >> (__builtin_ctzll(v) + l1));
}

ld solve() {

}

int main() {
    ll C = 1;
    while (1) {
        cin >> N >> M;
        if (N == 0 && M == 0) break;
        for (ll i = 0; i < N; i++) for (ll j = 0; j < M; j++) cin >> T[i][j];

        ld ans;
        for (ull k = 1; k <= N; k++) {
            ull perm = (1 << k) - 1, stop = 1 << N;
            // cout << "k=" << k << endl;
            
            ans = numeric_limits<ld>::max();
            while (perm < stop) {
                // bitset<64> b(perm);
                // cout << b << endl;
                
                ull poli = 0;
                ld best = numeric_limits<ld>::max();
                if (k == 1) {
                
                    ull b = 0;
                    for (ull i = 0; i < N; i++) if (testBit(perm, i)) {
                        b = i;
                        break;
                    }
                    for (ll j = 0; j < M; j++) if (best > T[b][j]) {
                        poli = 1 << j;
                        best = T[b][j];
                    }
                
                } else {
                
                    for (ull i = 0; i < N; i++) if (testBit(perm, i)) {
                        ull p = perm ^ (1 << i);
                        ull oldp = DP[p].fst; // dp poli
                        ld cand = DP[p].snd; // dp best
                        for (ull j = 0; j < M; j++) if (!testBit(oldp, j) && best > cand + T[i][j]) {
                            poli = oldp | (1 << j);
                            best = cand + T[i][j];
                        }
                    }
                
                }
                
                DP[perm] = make_pair(poli, best);
                perm = nextBitperm(perm);
                ans = min(ans, best);
            }
        }
       
        ans = (ld) ((ll) ((ans / (ld) N + 0.0051) * 100)) / 100; // rundungsfehler?!
        cout << setprecision(2) << fixed << ans << endl;
    }
    return 0;
}

