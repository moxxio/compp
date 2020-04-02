#include <bits/stdc++.h>
#define fst first
#define snd second
#define MAXN 100

using namespace std;
typedef long long int llong;
typedef vector<int> vi;
typedef set<int> si;
typedef pair<int, int> pii;

vector<llong> adj[2 * MAXN];

llong dis[MAXN][MAXN];
pair<llong, llong> stu[MAXN];
pair<llong, llong> tut[MAXN];

bool matched[2 * MAXN];
bool matchedEdge[2 * MAXN][2 * MAXN];
bool visited[2 * MAXN];

llong manhattan(llong x1, llong y1, llong x2, llong y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

bool dfs(llong node, bool backEdge, bool recursive) {
    if (visited[node]) return false;

    visited[node] = true;

    if (!matched[node] && !recursive) {
        matched[node] = true;
        return true;
    }

    for (llong nb : adj[node]) {
        if (matchedEdge[node][nb] == backEdge && dfs(nb, !backEdge, false)) {
            matchedEdge[node][nb] = !matchedEdge[node][nb];
            matchedEdge[nb][node] = !matchedEdge[nb][node];
            matched[node] = true;
            return true;
        }
    }

    return false;
}

llong match(llong n) {
    memset(matched, 0, sizeof(matched));
    memset(matchedEdge, 0, sizeof(matchedEdge));

    llong nMatched = 0;
    while (true) {
        bool foundMatch = false;
        for (llong i = 0; i < n; ++i) {
            if (matched[i]) continue;

            memset(visited, 0, sizeof(visited));
            bool ret = dfs(i, false, true);
            if (ret) {
                ++nMatched;
                foundMatch = true;
            }
        }
        if (!foundMatch) break;
    }

    return nMatched;
}

void debug(llong n) {
    for (llong i = 0; i < n; i++) {
        cout << "i=" << i << ": ";
        for (llong u : adj[i]) cout << u << " ";
    }
    cout << endl;
    for (llong i = n; i < n + n; i++) {
        cout << "i=" << i << ": ";
        for (llong u : adj[i]) cout << u << " ";
    }
    cout << endl;
}

int main() {
    llong x, y, xs, ys, n;
    cin >> n;
    llong nn = n + n;

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
            // cout << "dis[" << j << "][" << i << "]=" << dis[j][i] << endl;
        }
    }

    llong l = 0;
    llong r = 400000000; // 4 * 10 ** 8
    while (l < r) {
        llong m = (l + r) / 2;
        // cout << "m=" << m << endl;

        for (llong i = 0; i < nn; i++) {
            adj[i].clear();
        }
        for (llong i = 0; i < n; i++) {
            for (llong j = 0; j < n; j++) {
                if (dis[i][j] <= m) {
                    adj[i].push_back(j + n);
                    adj[j + n].push_back(i);
                }
            }
        }
        // debug(n);

        llong matched = match(nn);
        // cout << "matched=" << matched << endl;
        if (matched == n) {
            r = m;
        } else {
            l = m + 1;
        }
    }

    cout << r << endl;
    return 0;
}
