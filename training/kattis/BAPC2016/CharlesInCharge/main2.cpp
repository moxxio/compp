#include <bits/stdc++.h>
#define fst first
#define snd second

using namespace std;
typedef long long llong;
typedef vector<int> vi;
typedef set<int> si;
typedef pair<int, int> pii;

constexpr llong INF = 0x3f3f3f3f3f3f3f3fLL;

struct Triple {
    llong a, b, c; // distance, max length of a highway, vertex
    Triple(llong _a, llong _b, llong _c) : a(_a), b(_b), c(_c) {}
    bool operator<(const Triple& other) const {
        return a > other.a;
    }
};

llong n, m, x;
vector<pair<llong, llong>> adj[10101]; // fst length, snd vertex
bool vis[10101];
llong dst[10101];

llong dijkstra(llong longest_allowed) {
    priority_queue<Triple> pq;
    pq.push(Triple(0, 0, 1));
    memset(vis, 0, sizeof(vis));
    for (llong& x : dst) x = -1;
    llong best_dist = -1;
    while (!pq.empty()) {
        llong d = pq.top().a; // distance so far
        llong e = pq.top().b; // longest highway used
        llong u = pq.top().c; pq.pop(); // current city
        if (vis[u]) continue;
        vis[u] = 1;
        dst[u] = d;
        if (u == n) {
            best_dist = d;
            break;
        }
        for (pair<llong, llong> tmp : adj[u]) {
            llong d2 = tmp.fst;
            if (d2 > longest_allowed) continue;
            llong v = tmp.snd;
            llong d3 = d + d2;
            if (dst[v] == -1 || dst[v] > d3) {
                pq.push(Triple(d3, max(e, d2), v));
            }
        }
    }
    return best_dist;
}

int main() {
    cin >> n >> m >> x;
    long double perc = 1. + ((long double) x / 100.);

    // cout << n << " " << m << " " << x << endl;
    for (llong i = 0; i < m; i++) {
        llong a, b, t;
        cin >> a >> b >> t;
        adj[a].push_back(make_pair(t, b));
        adj[b].push_back(make_pair(t, a));
    }

    llong best_dist = dijkstra(INF);
    long double max_dist_allowed = perc * best_dist;
    llong lo = 0, hi = 1010101010L;
    while (lo < hi) {
        llong mid = (lo + hi) / 2;
        llong d = dijkstra(mid);
        if (d == -1 || d > max_dist_allowed) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }

    cout << hi << endl;
    return 0;
}
