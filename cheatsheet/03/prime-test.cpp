#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool is_prime(ll n) {
    if (n == 2) return 1;
    if (n <= 1 || n % 2 == 0) return 0;
    ll r = (ll) sqrt(n);
    for (ll d = 3; d <= r; d += 2) if (n % d == 0) return 0;
    return 1;
}
