#include <bits/stdc++.h>
#define fst first
#define snd second
#define INF 2305843009213693952

using namespace std;
typedef long long llong;
typedef vector<int> vi;
typedef set<int> si;
typedef pair<int, int> pii;

struct Triple {
    llong l, max, c;
    Triple(llong _l, llong _max, llong _c) : l(_l), max(_max), c(_c) {}
    bool operator<(const Triple& other) const {
        return l > other.l;
    }
};

llong n, m, x;
vector<pair<llong, llong>> adj[10101]; // fst length, snd vertex
llong vis[10101];

int main() {
    cin >> n >> m >> x;
    long double percentage = 1. + ((long double) x / 100.);
    // cout << n << " " << m << " " << x << endl;
    // cout << "percentage=" << percentage << endl;
    for (llong i = 0; i < m; i++) {
        llong a, b, t;
        cin >> a >> b >> t;
        adj[a].push_back(make_pair(t, b));
        adj[b].push_back(make_pair(t, a));
    }

    // cout << "hello" << endl;
    priority_queue<Triple> pq;
    pq.push(Triple(0, 0, 1));
    memset(vis, 0, sizeof(vis));
    llong best_dist = -1;
    llong best_akku = INF;
    while (!pq.empty()) {
        llong len = pq.top().l;
        llong mxx = pq.top().max;
        llong u = pq.top().c;
        pq.pop();
        if (best_dist >= 0 && len > best_dist * percentage) {
            // cout <<
            continue;
        }
        if (u == n) {
            if (best_dist < 0) best_dist = len, best_akku = mxx;
            else best_akku = min(best_akku, mxx);
            continue;
        }

        for (pair<llong, llong> tmp : adj[u]) {
            llong dis = tmp.fst;
            llong v = tmp.snd;
            pq.push(Triple(len + dis, max(mxx, dis), v));
        }
    }

    cout << best_akku << endl;
    return 0;
}
