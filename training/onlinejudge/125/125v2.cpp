#include <bits/stdc++.h>
#define fst first
#define snd second
#define MAXN 31

using namespace std;
typedef long long llong;
typedef vector<int> vi;
typedef set<int> si;
typedef pair<int, int> pii;

int paths[MAXN][MAXN];
vi adj[MAXN];
bool visited[MAXN];

void dfs(int s, int t, int v, bool found) {
	visited[v] = 1;
	if (t == v) {
		found = 1;
		if (s != t && paths[s][t] >= 0) paths[s][t]++; 
	}
	for (int u : adj[v]) {
		if (paths[s][t] == -1) return;
		if (visited[u] && found) paths[s][t] = -1;
		if (!visited[u]) dfs(s, t, u, found);
	}
	visited[v] = 0;
}

bool find_cycles(int s, int t, int v) {
	if (t == v) return 0;
	visited[v] = 1;
	for (int u : adj[v]) {
		if (visited[u] && (paths[u][t] > 0 || paths[u][t] == -1)) return 1;
		if (find_cycles(s, t, u)) return 1;
	}
	visited[v] = 0;
	return 0;
}

int main() {
	int a, b, t, z = 0;
	while (cin >> t) {
        int n = 0;
        memset(paths, 0, sizeof paths);
        for (int i = 0; i < MAXN; i++) adj[i].clear();
        for (int i = 0; i < t; i++) {
            cin >> a >> b;
            n = max(a, max(b, n));
            adj[a].push_back(b);
        }
        n++;

		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
			memset(visited, 0, sizeof visited);
			dfs(i, j, i, 0);
		}
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (paths[i][j] > 0 && find_cycles(i, j, i)) {
			paths[i][j] = -1;
		}

        cout << "matrix for city " << z << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cout << paths[i][j] << " ";
            cout << endl;
        }
        z++;
	}
    return 0;
}
