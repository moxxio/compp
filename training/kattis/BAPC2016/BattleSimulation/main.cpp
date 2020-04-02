#include <bits/stdc++.h>
#define fst first
#define snd second

using namespace std;
typedef long long llong;
typedef vector<int> vi;
typedef set<int> si;
typedef pair<int, int> pii;

int main() {
    string line;
    getline(cin, line);
    deque<char> s;

    int r = 3, b = 3, l = 3;
    for (int i = 0; i < line.length(); i++) {
        char c = line[i];
        switch (c) {
            case 'R':
            r = 0;
            s.push_back('S');
            break;
            case 'B':
            b = 0;
            s.push_back('K');
            break;
            case 'L':
            l = 0;
            s.push_back('H');
            break;
        }
        if (r < 3 && b < 3 && l < 3) {
            s.pop_back(); s.pop_back(); s.pop_back();
            s.push_back('C');
            r = 3, b = 3, l = 3;
        }
        r++; b++; l++;
    }

    while (!s.empty()) {
        cout << s.front();
        s.pop_front();
    }
    cout << endl;
    return 0;
}
