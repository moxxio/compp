#include <bits/stdc++.h>
#define fst first
#define snd second
#define N 300

using namespace std;
typedef long long llong;
typedef vector<int> vi;
typedef set<int> si;
typedef pair<int, int> pii;

int n, m;
vi adj[N];
int col[N]; // coloring

string claw() { // 3 regular g has a claw decomp <=> g is bipartite <=> g is 2-colorable
    queue<int> q;
    col[0] = 1;
    q.push(0);

    while(!q.empty()) {
        int u = q.front(); q.pop();

        for (int v : adj[u]) {
            if (col[u] == col[v]) return "NO";
            else if (col[v] == 0){
                col[v] = -col[u];
                q.push(v);
            }
        }
    }

    return "YES";
}

int main() {
    for (cin >> n; n != 0; cin >> n) {
        for (int i = 0; i < n; i++) adj[i].clear();
        memset(col, 0, sizeof col);
        m = 0;

        int a, b;
        for (cin >> a >> b; a != 0 || b != 0; cin >> a >> b) {
            a--; b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
            m++;
        }

        if (m % 3 != 0) cout << "NO" << endl;
        else if (m == 0) cout << "YES" << endl;
        else cout << claw() << endl;
    }

    return 0;
}
