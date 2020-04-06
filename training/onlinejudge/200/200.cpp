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
constexpr ll MAXN = 30;

bool adj[MAXN][MAXN];
ll p, n, v[MAXN];
ll fg;
ll od[MAXN];

unordered_map<char, ll> char2num;
char num2char[MAXN];
vs lines;

void dfs(ll a) {
    if (v[a] == 1) fg = 1;
    if (v[a]) return;
    v[a] = 1;
    for (ll i = 0; i < MAXN; ++i) if (adj[a][i]) dfs(i);
    v[a] = 2;
    od[p] = a;
    p--;
}

void topsort(ll n) {
    for (ll i = 0; i < n; ++i) v[i] = 0;
    fg = 0; p = n - 1;
    for (ll i = 0; i < n; ++i) if (!v[i]) dfs(i);
}

void build_graph(ll lo, ll hi, ll de) { // high, low, depth
    ll run = -1;
    // cout << "bg " << lo << " " << hi << " " << de << endl;
    for (ll i = lo; i < hi - 1; i++) {
        if (de >= lines[i].length()) continue;

        if (lines[i][de] == lines[i+1][de]) {
            if (run == -1) run = i;
            if (i >= hi - 2) {
                build_graph(run, hi, de+1);
                run = -1;
            }
        } else {
            if (run != -1) {
                build_graph(run, i+1, de+1);
                run = -1;
            }
            adj[char2num[lines[i][de]]][char2num[lines[i+1][de]]] = 1;
            // cout << lines[i][de] << " to " << lines[i+1][de] << endl;
        }
    }
}

int main() {
    n = 0;
    for (ll i = 0; i < MAXN; i++) od[i] = -1;
    memset(adj, 0, sizeof(adj));
    while (1) {
        string line;
        cin >> line;
        if (line == "#") break;
        for (char c : line) {
            auto it = char2num.find(c);
            if (it == char2num.end()) {
                char2num[c] = n;
                num2char[n] = c;
                n++;
            }

        }
        lines.push_back(line);
    }
    build_graph(0, lines.size(), 0);
    topsort(n);
    for (ll i : od) {
        if (i == -1) break;
        cout << num2char[i];
    }
    cout << endl;
    return 0;
}
