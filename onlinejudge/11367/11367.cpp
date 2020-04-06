#include <bits/stdc++.h>
#define fst first
#define snd second
#define N 1000
#define C 101
#define INF 2147483647

using namespace std;
typedef long long llong;
typedef vector<int> vi;
typedef set<int> si;
typedef pair<int, int> pii;

int n, m; // vertices, edges
int p[N]; // fuel prices
int d[N][N]; // distances
vi adj[N];
int q; // number of queries
int c, s, t; // capacity, start, goal
int dp[N][C];

struct roadtrip {
    int curr, cost, tank;
    roadtrip(int _curr, int _cost, int _tank) : curr(_curr), cost(_cost), tank(_tank) {}
    bool operator<(const roadtrip& e) const {
        return cost > e.cost;
    }
};

int dijkstra() {
    priority_queue<roadtrip> pq;
    pq.push(roadtrip(s, 0, 0));
    for (int i = 0; i < N; i++) for (int j = 0; j < C; j++) dp[i][j] = INF;

    while(!pq.empty()) {
        roadtrip r = pq.top();
        pq.pop();

        if (r.curr == t) return r.cost;
        if (r.cost > dp[r.curr][r.tank]) continue;
        int new_cost = r.cost + p[r.curr];
        if (r.tank < c && new_cost < dp[r.curr][r.tank + 1]) {
            dp[r.curr][r.tank + 1] = new_cost;
            pq.push(roadtrip(r.curr, new_cost, r.tank + 1));
        }

        for (int next : adj[r.curr]) {
            int new_tank = r.tank - d[r.curr][next];
            if (new_tank >= 0 && r.cost < dp[next][new_tank]) {
                dp[next][new_tank] = r.cost;
                pq.push(roadtrip(next, r.cost, new_tank));
            }
        }
    }

    return -1;
}

int main() {
    memset(p, 0, sizeof p);
    memset(d, 0, sizeof d);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < m; i++) {
        int u, v, dist;
        cin >> u >> v >> dist;
        d[u][v] = dist;
        d[v][u] = dist;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> q;
    for (int i = 0; i < q; i++) {


        cin >> c >> s >> t;
        int ans = dijkstra();
        if (ans == -1) cout << "impossible" << endl;
        else cout << ans << endl;
    }

    return 0;
}
