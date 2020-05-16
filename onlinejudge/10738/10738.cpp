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
constexpr ll MAXN = 1000001;
constexpr ll MAXP = 78498;

ll primes_count = 0;
ll primes[MAXP];
ll is_prime[MAXN];
ll M[MAXN], mu[MAXN];

void sieve() {
    memset(is_prime, 0, sizeof(is_prime));
    for (ll i = 2; i < MAXN; i++) is_prime[i] = 1, mu[i] = 1; 
    primes_count = 0;
    for (ll i = 2; i < MAXN; i++) if (is_prime[i]) {
        primes[primes_count++] = i;
        mu[i] = -1;
        for (ll j = 2*i; j < MAXN; j+=i) is_prime[j] = 0, mu[j] *= -1;
        for (ll j = i*i; j < MAXN; j+=i*i) mu[j] = 0;
    }
}

void calc() {
    M[0] = 0, mu[0] = 0, mu[1] = 1;
    for (ll i = 1; i < MAXN; i++) {
        M[i] = M[i-1] + mu[i];
    }
}

int main() {
    sieve();
    calc();
    while (1) {
        ll N;
        cin >> N;
        if (N == 0) break;
        printf("%8lld%8lld%8lld\n", N, mu[N], M[N]);
    }
    return 0;
}

