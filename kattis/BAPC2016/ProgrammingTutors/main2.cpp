#include <bits/stdc++.h>
#define fst first
#define snd second
#define MAXN 100
#define INF 9223372036854775807L

using namespace std;
typedef long long int llong;
typedef vector<int> vi;
typedef set<int> si;
typedef pair<int, int> pii;

llong n;
llong dis[MAXN][MAXN];
vector<llong> adj[2 * MAXN + 2];
bool cap[2 * MAXN + 2][2 * MAXN + 2];
pair<llong, llong> stu[MAXN];
pair<llong, llong> tut[MAXN];

llong manhattan(llong x1, llong y1, llong x2, llong y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

bool bfs(llong s, llong t, vector<llong>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<llong> q;
    q.push(s);

    while (!q.empty()) {
        llong cur = q.front();
        q.pop();
        for (llong next : adj[cur]) {
            if (parent[next] == -1 && cap[cur][next]) {
                parent[next] = cur;
                if (next == t)
                    return 1;
                q.push(next);
            }
        }
    }
    return 0;
}

llong ford_falkerson(llong s, llong t) {
    llong flow = 0;
    vector<llong> parent(n);

    while (bfs(s, t, parent)) {
        flow++;
        llong cur = t;
        while (cur != s) {
            llong prev = parent[cur];
            cap[prev][cur] = 0;
            cap[cur][prev] = 1;
            cur = prev;
        }
    }

    return flow;
}

void debug() {
    cout << "s: ";
    for (llong u : adj[200]) cout << u << " ";
    cout << endl;
    for (llong i = 0; i < n; i++) {
        cout << "i=" << i << ": ";
        for (llong u : adj[i]) cout << u << " ";
    }
    cout << endl;
    for (llong i = MAXN; i < n + MAXN; i++) {
        cout << "i=" << i << ": ";
        for (llong u : adj[i]) cout << u << " ";
    }
    cout << endl;
    cout << "t: ";
    for (llong u : adj[201]) cout << u << " ";
    cout << endl;
}

int main() {
    cin >> n;
    llong x, y, xs, ys;
    for (llong i = 0; i < n; i++) {
        adj[200].push_back(i);
        adj[i].push_back(200);
        for (llong j = MAXN; j < n + MAXN; j++) {
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
        adj[i + MAXN].push_back(201);
        adj[201].push_back(i + MAXN);
    }

    for (llong i = 0; i < n; i++) {
        cin >> x >> y;
        stu[i] = make_pair(x, y);
    }

    for (llong i = 0; i < n; i++) {
        cin >> x >> y;
        tut[i] = make_pair(x, y);
        for (llong j = 0; j < n; j++) {
            xs = stu[j].fst;
            ys = stu[j].snd;
            dis[j][i] = manhattan(x, y, xs, ys);
        }
    }

    llong l = 0;
    llong r = 400000000;
    while (l < r) {
        llong m = (l + r) / 2;
        cout << "m=" << m << endl;

        memset(cap, 0, sizeof cap);
        for (llong i = 0; i < n; i++) {
            for (llong j = 0; j < n; j++) {
                if (dis[i][j] <= m) {
                    cap[i][j + MAXN] = 1;
                }
            }
            cap[200][i] = 1;
            cap[i + MAXN][201] = 1;
        }

        debug();

        llong flow = ford_falkerson(200, 201);
        cout << "flow=" << flow << endl;
        if (n == flow) {
            r = m;
        } else {
            l = m + 1;
        }
    }

    cout << r << endl;
    return 0;
}
