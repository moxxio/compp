#include <bits/stdc++.h>
#define fst first
#define snd second
#define N 101

using namespace std;
typedef long long llong;
typedef vector<int> vi;
typedef set<int> si;
typedef pair<int, int> pii;

int n;
vi adj[N];
bool vis[N];

void debug() {
    cout << "DEBUG" << endl;
	for (int i = 1; i <= n; i++) {
		cout << i << ": ";
		for (int j : adj[i]) {
			cout << j << " ";
		}
		cout << endl;
	}
}

void dfs(int v, int z) {
	vis[v] = 1;
	for (int u : adj[v]) {
		if (!vis[u] && u != z) dfs(u, z);
	}
}

int main() {
	for (cin >> n; n != 0; cin >> n) {
        // cout << "n=" << n << endl;
		for (int i = 1; i <= n; i++) adj[i].clear();

		bool done = 0;
		while (!done) {
			string line;
			getline(cin, line);
            if (line == "") continue;
            // cout << "line=" << line << endl;
			istringstream is(line);

			int p1 = -1;
			for (int j; is >> j; ) {
				if (j == 0) {
                    done = 1;
                    break;
                }
				// cout << "j=" << j << endl;

				if (p1 == -1) p1 = j;
				else {
					if (find(adj[p1].begin(), adj[p1].end(), j) == adj[p1].end()) adj[p1].push_back(j);
					if (find(adj[j].begin(), adj[j].end(), p1) == adj[j].end()) adj[j].push_back(p1);
				}
			}
		}

		// debug();
		int cut = 0;
		for (int i = 1; i <= n; i++) {
			memset(vis, 0, sizeof vis);
			vis[i] = 1;

			if (i == 1) dfs(2, i);
			else dfs(1, i);

			bool any = 1;
			for (int j = 1; j <= n && any; j++) any &= vis[j];
			if (!any) cut++;
		}
		cout << cut << endl;
	}
    // cout << "n=" << n << endl;

    return 0;
}
