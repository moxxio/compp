#include <bits/stdc++.h>
#define fst first
#define snd second
#define N 50
#define INF 2147483647

using namespace std;
typedef long long llong;
typedef vector<int> vi;
typedef set<int> si;
typedef pair<int, int> pii;

int n, m;
vi adj[N];
int cost[N][N];
bool vis[N];

int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int cur = q.front().fst;
        int flow = q.front().snd;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && cost[cur][next] > 0) {
                parent[next] = cur;
                int new_flow = min(flow, cost[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

void dfs(int s) {
    vis[s] = 1;
    for (int t : adj[s]) if (!vis[t] && cost[s][t] > 0) dfs(t);
}

void minCut(int s, int t) {
    int flow = 0;
    vector<int> parent(n);
    int new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            cost[prev][cur] -= new_flow;
            cost[cur][prev] += new_flow;
            cur = prev;
        }
    }

    // cout << flow << endl;
    memset(vis, 0, sizeof vis);
    dfs(0);

    for (int i = 0; i < n; i++) {
        for (int j : adj[i]) {
            if (vis[i] && !vis[j]) cout << i+1 << " " << j+1 << endl;
        }
    }
    cout << endl;
}

int main() {
    for (cin >> n >> m; n != 0 || m != 0; cin >> n >> m) {
        for (int i = 0; i < n; i++) adj[i].clear();
        //for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cost[i][j] = -1;
        memset(cost, 0, sizeof cost);

        for (int i = 0; i < m; i++) {
            int u, v, c;
            cin >> u >> v >> c;
            u--; v--;

            cost[u][v] = c;
            cost[v][u] = c;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        minCut(0, 1);
    }

    return 0;
}
