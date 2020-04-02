#include <bits/stdc++.h>
#define fst first
#define snd second

using namespace std;
typedef long long llong;
typedef vector<int> vi;
typedef set<int> si;
typedef pair<int, int> pii;

int q;

bool is_prime(llong n) {
    if (n == 2) return 1;
    if (n <= 1 || n % 2 == 0) return 0;
    llong r = (llong) sqrt(n);
    for (llong d = 3; d <= r; d += 2) if (n % d == 0) return 0;
    return 1;
}

llong fast_exp(llong b, llong e) { // only e >= 0
    if (e == 0) return 1;
    if (e == 1) return b;
    llong ans = fast_exp(b, e / 2);
    ans = ans * ans;
    if (e % 2 == 0) return ans;
    else return ans = ans * b;
}

int main() {
    cin >> q;
    llong l = (llong) log2(q);
    // cout << "log2=" << l << endl;
    for (llong k = 1; k <= l; k++) {
        llong m = (llong) pow((long double) q, 1. / (long double) k);
        llong n = fast_exp(m, k);
        // cout << "m=" << m << ", n=" << n << endl;
        if (n == q && is_prime(m)) {
            cout << "yes" << endl;
            return 0;
        }
    }
    cout << "no" << endl;
    return 0;
}
