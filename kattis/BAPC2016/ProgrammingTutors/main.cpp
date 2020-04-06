#include <bits/stdc++.h>
#define fst first
#define snd second
#define MAXN 100

using namespace std;
typedef long long int llong;
typedef vector<int> vi;
typedef set<int> si;
typedef pair<int, int> pii;

struct Dist {
    llong s, t, d;
    Dist(llong _s, llong _t, llong _d) : s(_t), t(_t), d(_d) {}
    bool operator<(const Dist& other) const {
        return d > other.d;
    }
};

llong n;
llong dis[MAXN][MAXN];
pair<llong, llong> stu[MAXN];
pair<llong, llong> tut[MAXN];

int main() {
    cin >> n;
    llong x, y, xs, ys;

    for (llong i = 0; i < n; i++) {
        cin >> x >> y;
        stu[i] = make_pair(x, y);
    }

    vector<Dist> matching;
    for (llong i = 0; i < n; i++) {
        cin >> x >> y;
        tut[i] = make_pair(x, y);
        for (llong j = 0; j < n; j++) {
            xs = stu[j].fst;
            ys = stu[j].snd;
            dis[j][i] = abs(x - xs) + abs(y - ys);
        }
        matching.push_back(Dist(i, i, dis[i][i]));
    }

    llong best = 1L << 60;
/*
    for (llong k = 0; k < 100; k++) {
        matching.clear();
        vector<llong> studis, tutors;
        for (llong i = 0; i < n; i++) {
            studis.push_back(i);
            tutors.push_back(i);
        }
        random_shuffle(studis.begin(), studis.end());
        random_shuffle(tutors.begin(), tutors.end());
        for (llong i = 0; i < n; i++) {
            matching.push_back(Dist(studis[i], tutors[i], dis[studis[i]][tutors[i]]));
        }
*/
        bool improve = 1;
        while (improve) {
            sort(matching.begin(), matching.end());
            for (llong i = 0; i < n; i++) cout << matching[i].d << " ";
            cout << endl;
            improve = 0;
            Dist worst = matching[0];
            for (llong i = 1; i < n; i++) {
                Dist next = matching[i];
                if (max(worst.d, next.d) > max(dis[worst.s][next.t], dis[next.s][worst.t])) {
                    matching[0] = Dist(worst.s, next.t, dis[worst.s][next.t]);
                    matching[i] = Dist(next.s, worst.t, dis[next.s][worst.t]);
                    improve = 1;
                    break;
                }
            }
        }
        best = min(best, matching[0].d);
    //}

    cout << best << endl;
    return 0;
}
