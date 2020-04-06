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

ll b, b2, n;
vll A, factors, digits, subsets;
ll num_of_factors; // n
ll num_of_subsets; // m
bool flag = 0;

bool less_than(vll& v1, vll& v2) {
    if (v1.size() < v2.size()) return 0;
    if (v1.size() > v2.size()) return 1;
    for (ll i = 0; i < v1.size(); i++) {
        if (v1[i] < v2[i]) return 0;
        if (v1[i] > v2[i]) return 1;
    }
    return 0;
}

void print_arr(vll& arr) {
    for (ll x : arr) cout << x << " ";
    cout << endl;
}

ll construct_number(vll& tmp_digits) {
    ll tmp = 1;
    ll ans = 0;
    // print_arr(tmp_digits);
    for (ll i = tmp_digits.size() - 1; i >= 0; i--) {
        ans += tmp * tmp_digits[i];
        tmp *= b;
        // cout << "tmp=" << tmp << endl;
        // cout << "ans=" << ans << endl;
    }
    return ans;
}

void proc_f(ll, ll, ll);
void proc_b(ll, ll, ll);

void visit() { // do something with A
    // cout << "partition" << endl;
    // print_arr(A);
    vll tmp_digits(num_of_subsets, 1);
    bool valid = 1;
    for (ll i = 0; i < num_of_factors; i++) {
        ll j = A[i + 1];
        tmp_digits[j] *= factors[i];
        if (tmp_digits[j] >= b) {
            valid = 0;
            break;
        }
    }
    // cout << "digits" << endl;
    // print_arr(tmp_digits);
    // cout << "valid=" << valid << endl;
    if (valid) {
        sort(tmp_digits.begin(), tmp_digits.end());
        if (!flag) {
            subsets = A;
            digits = tmp_digits;
            flag = 1;
        }
        else if (less_than(digits, tmp_digits)) {
            subsets = A;
            digits = tmp_digits;
        }
    }
}

void proc_f(ll mu, ll nu, ll sigma) {
    if (mu == 2) {
        visit();
    } else {
        proc_f(mu - 1, nu - 1, (mu + sigma) % 2);
    }
    if (nu == mu + 1) {
        A[mu] = mu - 1;
        visit();
        while (A[nu] > 0) {
            A[nu] = A[nu] - 1;
            visit();
        }
    } else if (nu > mu + 1) {
        if ((mu + sigma) % 2 == 1) {
            A[nu - 1] = mu - 1;
        } else {
            A[mu] = mu - 1;
        }
        if ((A[nu] + sigma) % 2 == 1) {
            proc_b(mu, nu - 1, 0);
        } else {
            proc_f(mu, nu - 1, 0);
        }
        while (A[nu] > 0) {
            A[nu] = A[nu] - 1;
            if ((A[nu] + sigma) % 2 == 1) {
                proc_b(mu, nu - 1, 0);
            } else {
                proc_f(mu, nu - 1, 0);
            }
        }
    }
}

void proc_b(ll mu, ll nu, ll sigma) {
    if (nu == mu + 1) {
        while (A[nu] < mu - 1) {
            visit();
            A[nu] = A[nu] + 1;
        }
        visit();
        A[mu] = 0;
    } else if (nu > mu + 1) {
        if ((A[nu] + sigma) == 1) {
            proc_f(mu, nu - 1, 0);
        } else {
            proc_b(mu, nu - 1, 0);
        }
        while (A[nu] < mu - 1) {
            A[nu] = A[nu] + 1;
            if ((A[nu] + sigma) == 1) {
                proc_f(mu, nu - 1, 0);
            } else {
                proc_b(mu, nu - 1, 0);
            }
        }
        if ((mu + sigma) % 2 == 1) {
            A[nu - 1] = 0;
        } else {
            A[mu] = 0;
        }
    }
    if (mu == 2) {
        visit();
    } else {
        proc_b(mu - 1, nu - 1, (mu + sigma) % 2);
    }
}

int main() {
    cin >> b >> n;
    b2 = (b - 1) / 2;

    ll n1 = n; // factorise n
    while (n1 % 2 == 0) {
        n1 = n1 / 2;
        factors.push_back(2);
    }
    for (ll q = 3; n1 > 1 && q <= b; q += 2) {
        while (n1 % q == 0) {
            n1 = n1 / q;
            factors.push_back(q);
        }
    }
    if (n1 > 1) {
        cout << "impossible" << endl;
        return 0;
    }
    // cout << "factors=" << factors.size() << endl;
    // print_arr(factors);

    num_of_factors = 0; // number of factors to consider to multiply together
    while (factors[num_of_factors] <= b2 && num_of_factors < factors.size()) num_of_factors++;
    if (num_of_factors == 0) { // all factors are > (b - 1) / 2
        ll ans = construct_number(factors);
        cout << ans << endl;
        return 0;
    }

    for (ll m = 1; m < num_of_factors && !flag; m++) {
        num_of_subsets = m;
        A.clear();
        A.push_back(-1); // ignore index 0, knuth starts with index 1
        for (ll j = 1; j <= num_of_factors - m; j++) A.push_back(0);
        for (ll j = 1; j <= m; j++) A.push_back(j - 1);
        if (m == 1) visit();
        else proc_f(m, num_of_factors, 0);
    }

    // cout << "num=" << num_of_factors << endl;
    // cout << "digits" << endl;
    // print_arr(digits);
    while (num_of_factors < factors.size()) digits.push_back(factors[num_of_factors]);
    sort(digits.begin(), digits.end());
    ll ans = construct_number(digits);
    cout << ans << endl;
    return 0;
}
