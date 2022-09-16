#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long

const int mxN = 2e5;
int n, x, a[mxN];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    ll s = 0;
    map<ll, int> m;
    m[0] = 1;
    ll cnt = 0;
    for (int i = 0; i < n; ++i) {
        s += a[i];
        // note how to take mod of -ve numbers
        cnt += m[(s % n + n) % n];
        m[((s % n) + n) % n]++;
    }

    cout << cnt << "\n";
}
