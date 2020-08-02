#include <bits/stdc++.h>
#define fst first
#define snd second

using namespace std;
typedef long long ll;
// typedef __int128 lll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<string> vs;

constexpr int oo = 0x3f3f3f3f;
constexpr ll ooo = 0x3f3f3f3f3f3f3f3fLL;
constexpr ld eps = 1e-9;
constexpr ld PI = 2.0 * acos(0.0);

struct activity {
    string name;
    ll fun, len;
    activity(string nameP, ll funP, ll lenP) : name(nameP), fun(funP), len(lenP) {}
    bool operator<(const activity &a) {
        return fun > a.fun;
    }
};

ll T, N, M;
vector<activity> activities;

int main() {
    cin >> T;
    ll t = 1;
    while (t <= T) {
        activities.clear();
        cin >> N >> M;
        M = 60 * M;
        
        for (ll i = 0; i < N; i++) {
            string n;
            ll f, l;
            cin >> n >> f >> l;
            activities.push_back(activity(n, f, l));
        }
        sort(activities.begin(), activities.end());
        
        ll fun = 0;
        for (ll i = 0; i < activities.size() && M > 0; i++) {
            ll m = min(M, activities[i].len);
            fun += m * activities[i].fun;
            M -= activities[i].len;
        }
        
        cout << "Case #" << t << ": " << fun << endl;
        t++;
    }
    return 0;
}
