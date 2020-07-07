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
constexpr ll MAXN = 1010101;

string pat;
ll f[MAXN];

void kmpsetup() {
    ll k = 0, q = 2;
    for (f[0] = 0; q <= pat.length(); q++) {
        while(k > 0 && pat[k] != pat[q-1])
            k = f[k-1];
        if(pat[k] == pat[q-1])
            k++;
        f[q-1] = k;
    }
}

ll periode() {
    kmpsetup();
    ll n = pat.length();
    return n - f[n - 1];
}

int main() {
    while (1) {
        cin >> pat;
        if (pat == ".") break;
        kmpsetup();
        ll len = pat.length(), per = periode();
        cout << (len % per == 0 ? len / per : 1) << endl;
    }
    return 0;
}

