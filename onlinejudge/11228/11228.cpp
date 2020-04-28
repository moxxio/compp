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
constexpr ll MAXN = 1111;

struct edge {
    ll x, y;
    ld d;
};

bool operator<(const edge& e1, const edge& e2) { return e1.d < e2.d; }

vector<edge> e;
vll u;
ll pa[MAXN];
ll rk[MAXN];
ll pa1[MAXN];
ll rk1[MAXN];
ld roads;
ld rails;

ll ufind(ll i, ll* pa) {
    if (pa[i] != i) pa[i] = ufind(pa[i], pa);
    return pa[i];
}

ll uunion(ll a, ll b, ll* pa, ll* rk) {
    a = ufind(a, pa);
    b = ufind(b, pa);
    if (a == b) return 0;
    if (rk[a] > rk[b]) pa[b] = a;
    else pa[a] = b;
    if (rk[a] == rk[b]) rk[b]++;
    return 1;
}

void kruskal(ll n, ll m) {
    sort(e.begin(), e.end());
    for (ll i = 0; i < n; i++) {
        pa[i] = i;
        rk[i] = 0;
    }
    roads = 0;
    rails = 0;
    for (ll i = 0; i < m; i++) {
        u[i] = uunion(e[i].x, e[i].y, pa, rk);
        if (u[i]) {
            ll x = ufind(e[i].x, pa1);
            ll y = ufind(e[i].y, pa1);
            if (x == y) roads += e[i].d;
            else rails += e[i].d;
        }
    }
}

ld distance(pll& c1, pll& c2) {
    ld dx = c1.fst - c2.fst;
    ld dy = c1.snd - c2.snd;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    ll c;
    cin >> c;
    ll counter = 1;
    while (c-- > 0) {
        ll n, r;
        cin >> n >> r;
        vector<pll> cities;

        for (ll i = 0; i < n; i++) {
            pa1[i] = i;
            rk1[i] = 0;
            ll x, y;
            cin >> x >> y;
            cities.push_back(make_pair(x, y));
        }
        e.clear();
        u.clear();
        ll m = 0;
        ll s = n;
        for (ll i = 0; i < cities.size(); i++) {
            pll c1 = cities[i];
            for (ll j = 0; j < cities.size(); j++) {
                if (i == j) continue;
                pll c2 = cities[j];
                ld d = distance(c1, c2);
                if (d <= r) s = s - uunion(i, j, pa1, rk1);
                e.push_back({i, j, d});
                m++;
            }
        }
        u.assign(m, 0);

        kruskal(n, m);
        cout << "Case #" << counter++ << ": " << s << " " << llround(roads) << " " << llround(rails) << endl;
    }
    return 0;
}
