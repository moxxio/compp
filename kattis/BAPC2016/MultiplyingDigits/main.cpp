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
vll factors;
vll subsets;
vll digits;

bool less_than(vll& v1, vll& v2) {
    if (v1.size() < v2.size()) return 0;
    if (v1.size() > v2.size()) return 1;
    for (ll i = 0; i < v1.size(); i++) {
        if (v1[i] < v2[i]) return 0;
        if (v1[i] > v2[i]) return 1;
    }
    return 0;
}

bool next_partition(vll& tmp_subsets, ll num_of_factors) {
    bool run = 0;
    for (ll i = num_of_factors - 1; i >= 0 && !run; i--) {
        // cout << "i=" << i << endl;
        if (i == 0) break;
        ll inc = -1;
        // cout << "inc=" << inc << endl;
        for (ll j = 0; j < i; j++) {
            // cout << "j=" << j << endl;
            // cout << "tmp[i]=" << tmp_subsets[i] << endl;
            // cout << "tmp[j]=" << tmp_subsets[j] << endl;
            if (tmp_subsets[i] == tmp_subsets[j]) {
                inc = i;
                break;
            }
        }
        if (inc == -1) continue;
        // cout << "next" << endl;
        tmp_subsets[inc]++;
        for (ll j = inc + 1; j < num_of_factors; j++) tmp_subsets[j] = 1;
        run = 1;
    }
    // cout << "return" << endl;
    return run;
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

    ll num_of_factors = 0; // number of factors to consider to multiply together
    while (factors[num_of_factors] <= b2 && num_of_factors < factors.size()) num_of_factors++;
    if (num_of_factors == 0) { // all factors are > (b - 1) / 2
        ll ans = construct_number(factors);
        cout << ans << endl;
        return 0;
    }

    vll tmp_subsets(num_of_factors, 1);
    // ll num_of_subsets = 1;
    bool found_valid = 0;
    bool run = 1;
    while (run) {
        // cout << "subsets" << endl;
        // print_arr(tmp_subsets);

        ll num_of_subsets = -1;
        for (ll x : tmp_subsets) num_of_subsets = max(num_of_subsets, x);
        vll tmp_digits(num_of_subsets, 1);
        bool valid = 1;
        for (ll i = 0; i < num_of_factors; i++) {
            ll j = tmp_subsets[i] - 1;
            tmp_digits[j] *= factors[i];
            if (tmp_digits[j] >= b) {
                valid = 0;
                // break;
            }
        }
        // cout << "digits" << endl;
        // print_arr(tmp_digits);
        // cout << "valid=" << valid << endl;
        if (valid) {
            sort(tmp_digits.begin(), tmp_digits.end());
            if (!found_valid) {
                subsets = tmp_subsets;
                digits = tmp_digits;
                found_valid = 1;
            }
            else if (less_than(digits, tmp_digits)) {
                subsets = tmp_subsets;
                digits = tmp_digits;
            }
        }
        found_valid |= valid;

        run = next_partition(tmp_subsets, num_of_factors);
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
