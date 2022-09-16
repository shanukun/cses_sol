#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long

const int mxN = 2e5;
int n, x, a[mxN];

int main() {
    cin >> n >> x;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll sm = 0;
    int cnt = 0;
    for (int i = 0, j = 0; i < n; ++i) {
        while (j < n && sm + a[j] <= x)
            sm += a[j++];
        if (sm == x) ++cnt;
        sm -= a[i];
    }
    cout << cnt << "\n";
}
