#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxN = 1e6, M = 1e9 + 7;

int n, x, a[mxN];
ll dp[mxN + 1];

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        dp[i] = 1e9;
        int m = i;
        while (m > 0) {
            int r = m % 10;
            m /= 10;
            dp[i] = min(dp[i - r] + 1, dp[i]);
        }
    }
    cout << dp[n];
}
