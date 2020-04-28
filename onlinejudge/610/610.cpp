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
constexpr MAXN = 1010;

vll adj[MAXN][2];
ll ccomp, comp[MAXN];
vll st;

void dfs(ll n, ll c, ll dir) {
    if (comp[n] != -1) return;
    comp[n] = c;
    for (ll i = 0; i < adj[n][dir].size(); i++)
        dfs(adj[n][dir][i], c, dir);
    st.push_back(n);
}

void kosaraju(ll n) {
    memset(comp, -1, sizeof(comp));
    st.clear();

    for (ll i = 0; i < n; i++) dfs(i, 0, 0);

    reverse(st.begin(), st.end());
    memset(comp, -1, sizeof(comp));
    ccomp = 0;

    for (ll i = 0; i < n; i++)
        if (comp[st[i]] == -1) dfs(st[i], ccomp++, 1);
}

int main() {

    return 0;
}
