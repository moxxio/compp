#include <bits/stdc++.h>
#define fst first
#define snd second

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<string> vs;

constexpr int oo = 0x3f3f3f3f;
constexpr ll ooo = 0x3f3f3f3f3f3f3f3fLL;
constexpr ld eps = 1e-7;
constexpr ld PI = 2.0 * acos(0.0);

ll n;
ll half = 30 * 60;

int main() {
    cin >> n;
    vll arrival(n);
    for (ll& t : arrival) cin >> t;

    ll unavailable = 0;
    ll time_updown = -1;
    ll time_new = 0;
    bool up = 0;
    ll waiting = 0;
    for (ll i = 0; i < arrival.size(); i++) {
        ll t = arrival[i];
        if (time_updown == -1) {
            time_updown = t + half - 60;
            // cout << "time_updown=" << time_updown << endl;
        }

        if (up) {
            if (t > time_updown + time_new + 2 * 60) {
                // cout << "down_at_t=" << t << endl;
                up = 0;
                unavailable += time_new + 60;
                time_new = 0;
                i--;
                time_updown = -1;
            } else {
                time_new += t - time_updown - time_new + 20;
                // cout << "time_new=" << time_new << endl;
            }
        } else {
            if (t >= time_updown) {
                // cout << "up_at_t=" << t << endl;
                up = 1;
                time_new = 60 + waiting * 20;
                // cout << "time_new=" << time_new << endl;
                waiting = 0;
                i--;
            } else {
                waiting++;
            }
        }
    }
    if (up) {
        unavailable += time_new + 60;
    } else {
        unavailable += 120 + waiting * 20;
    }

    cout << unavailable << endl;
    return 0;
}
