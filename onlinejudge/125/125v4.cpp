#include <bits/stdc++.h>
#define fst first
#define snd second
#define MAXN 31

using namespace std;
typedef long long llong;
typedef vector<int> vi;
typedef set<int> si;
typedef pair<int, int> pii;

int n;
// int adj[MAXN][MAXN];
int paths[MAXN][MAXN];

void floyd_warshall() {
    // first time to calc num of paths and find cycles
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            if (paths[i][k])
                for (int j = 0; j < n; j++)
                    if (paths[k][j]) {
                        if (i == j || paths[i][k] == -1 || paths[k][j] == -1) paths[i][j] = -1;
                        else paths[i][j] += paths[i][k] * paths[k][j];
                    }

    // second time to catch all cycles
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            if (paths[i][k])
                for (int j = 0; j < n; j++)
                    if (paths[k][j])
                        if (i == j || paths[i][k] == -1 || paths[k][j] == -1) paths[i][j] = -1;
}

int main() {
    int a, b, t, z = 0;
    while (cin >> t) {
        n = 0;
        // memset(adj, 0, sizeof adj);
        memset(paths, 0, sizeof paths);
        for (int i = 0; i < t; i++) {
            cin >> a >> b;
            n = max(a, max(b, n));
            // adj[a][b] = 1;
            paths[a][b] = 1;
        }
        n++;

        floyd_warshall();

        cout << "matrix for city " << z << endl;
        for (int i = 0; i < n; i++) {
            bool not_first_line = 0;
            for (int j = 0; j < n; j++) {
                if (not_first_line) cout << " ";
                else not_first_line = 1;
                cout << paths[i][j];
            }
            cout << endl;
        }
        z++;
    }
    return 0;
}
