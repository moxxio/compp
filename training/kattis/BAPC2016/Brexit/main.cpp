#include <bits/stdc++.h>
#define fst first
#define snd second
#define MAXC 200000

using namespace std;
typedef long long llong;
typedef vector<int> vi;
typedef set<int> si;
typedef pair<int, int> pii;

int c, p, x, l;
vi adj[MAXC];
bool out[MAXC];
int leaves[MAXC];

int main() {
    memset(out, 0, sizeof out);
    memset(leaves, 0, sizeof leaves);

    cin >> c >> p >> x >> l;
    x--; l--;
    for (int k = 0; k < p; k++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    q.push(l);
    while (!q.empty()) {
        int v = q.front(); q.pop();
        if (!out[v] && (leaves[v] >= (adj[v].size() + 1) / 2 || v == l)) {
            // cout << "city " << v << " leaves" << endl;
            out[v] = 1;
            if (v == x) {
                cout << "leave" << endl;
                return 0;
            }
            for (int u : adj[v]) {
                leaves[u]++;
                if (!out[u]) {
                    q.push(u);
                }
            }
        }
    }

    cout << "stay" << endl;
    return 0;
}
