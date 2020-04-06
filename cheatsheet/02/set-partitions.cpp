#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

void proc_f(ll, ll, ll);
void proc_b(ll, ll, ll);

void print_arr(vll& arr) {
    for (ll i = 1; i < arr.size(); i++) cout << arr[i] << " ";
    cout << endl;
}

void visit() {
    print_arr(A); // do something with A
}

vll A; // indicates in which partition an element is

void proc_f(ll mu, ll nu, ll sigma) {
    if (mu == 2) visit(); // do something
    else proc_f(mu - 1, nu - 1, (mu + sigma) % 2);
    if (nu == mu + 1) {
        A[mu] = mu - 1;
        visit();
        while (A[nu] > 0) {
            A[nu] = A[nu] - 1;
            visit();
        }
    } else if (nu > mu + 1) {
        if ((mu + sigma) % 2 == 1) A[nu - 1] = mu - 1;
        else A[mu] = mu - 1;
        if ((A[nu] + sigma) % 2 == 1) proc_b(mu, nu - 1, 0);
        else proc_f(mu, nu - 1, 0);
        while (A[nu] > 0) {
            A[nu] = A[nu] - 1;
            if ((A[nu] + sigma) % 2 == 1) proc_b(mu, nu - 1, 0);
            else proc_f(mu, nu - 1, 0);
        }
    }
}

void proc_b(ll mu, ll nu, ll sigma) {
    if (nu == mu + 1) {
        while (A[nu] < mu - 1) {
            visit();
            A[nu] = A[nu] + 1;
        }
        visit();
        A[mu] = 0;
    } else if (nu > mu + 1) {
        if ((A[nu] + sigma) == 1) proc_f(mu, nu - 1, 0);
        else proc_b(mu, nu - 1, 0);
        while (A[nu] < mu - 1) {
            A[nu] = A[nu] + 1;
            if ((A[nu] + sigma) == 1) proc_f(mu, nu - 1, 0);
            else proc_b(mu, nu - 1, 0);
        }
        if ((mu + sigma) % 2 == 1) A[nu - 1] = 0;
        else A[mu] = 0;
    }
    if (mu == 2) visit();
    else proc_b(mu - 1, nu - 1, (mu + sigma) % 2);
}

int main() {
    A.push_back(-1); // ignore index 0
    ll m = 3, n = 5; // m = number of partitions, n = number of elements
    for (ll j = 1; j <= n - m; j++) A.push_back(0); // init with {0,0,0,1,2}
    for (ll j = 1; j <= m; j++) A.push_back(j - 1); // n-m 0s, then 0 to m-1
    proc_f(m, n, 0);
    return 0;
}
