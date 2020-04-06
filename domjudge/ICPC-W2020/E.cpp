#include <bits/stdc++.h>
#define fst first
#define snd second

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<string> vs;

constexpr int oo = 0x3f3f3f3f;
constexpr ll ooo = 0x3f3f3f3f3f3f3f3fLL;
constexpr ld eps = 1e-9;
constexpr ld PI = 2.0 * acos(0.0);

ll n;
bool vis[10][10];

int main() {
    memset(vis, 0, sizeof(vis));
    cin >> n;
    string pos;
    cin >> pos;
    ll x = pos[0] - 'a';
    ll y = pos[1] - '1';
    vis[x][y] = 1;
    cout << "queen" << endl;
    while (y < n) {
        cout << char(x + 'a') << char(y + '1') << endl;
        vis[x][y] = 1;
        y++;
    }
    y--;
    if (x != 0 && x != n - 1) {
        x = 0;
        cout << char(x + 'a') << char(y + '1') << endl;
        vis[x][y] = 1;
    }
    ll move = 1;
    if (x == n - 1) move = -1;
    while (y >= 0) {
        if (vis[x + move][y]) {
            if (x + 2 * move < 0 || x + 2 * move >= n) {
                y--;
                if (y < 0) return 0;
                if (x + move >= 0 && x + move < n && !vis[x + move][y]) x = x + move;
                cout << char(x + 'a') << char(y + '1') << endl;
                move = -move;
                vis[x][y] = 1;
            } else {
                x = x + 2 * move;
                cout << char(x + 'a') << char(y + '1') << endl;
                vis[x][y] = 1;
            }
        } else {
            if (x + move < 0 || x + move >= n) {
                y--;
                if (y < 0) return 0;
                if (x + move >= 0 && x + move < n && !vis[x + move][y]) x = x + move;
                cout << char(x + 'a') << char(y + '1') << endl;
                move = -move;
                vis[x][y] = 1;
            } else {
                x = x + move;
                cout << char(x + 'a') << char(y + '1') << endl;
                vis[x][y] = 1;
            }
        }
    }
    return 0;
}
