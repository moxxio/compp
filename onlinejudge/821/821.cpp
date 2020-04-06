#include <bits/stdc++.h>
#define fst first
#define snd second
#define inf 9999

using namespace std;
typedef long long llong;
typedef vector<int> vi;
typedef set<int> si;
typedef pair<int, int> pii;

int dist[100][100];
int weight[100][100];

void floyd_warshall(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dist[i][j] = i == j ? 0 : weight[i][j];
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}

void debug(int n) {
	cout << "n = " << n << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << weight[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << dist[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	int a, b, c = 1;
	cin >> a >> b;

	while (a != 0 || b != 0) {
		int n = 0;
		map<int, int> translate;
		for (int i = 0; i < 100; i++) for (int j = 0; j < 100; j++) {
			weight[i][j] = i == j ? 0 : inf;
		}

		while (a != 0 || b != 0) {
			a--; b--;
			if (!translate.count(a)) translate[a] = n++;
			if (!translate.count(b)) translate[b] = n++;
			weight[translate[a]][translate[b]] = 1;
			cin >> a >> b;
		}
		floyd_warshall(n);
		int s = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				s += dist[i][j];
			}
		}
		// debug(n);
		
		cout << setprecision(3) << fixed << "Case " << c << ": average length between pages = " << ((double) s) / (n * (n - 1)) << " clicks" << endl;
		cin >> a >> b;
		c++;
	}

    return 0;
}
