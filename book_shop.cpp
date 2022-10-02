#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 1e3, mxX = 1e5, M = 1e9 + 7;

int n, x;
int a[mxN], b[mxN];
int dp[mxN + 1][mxX + 1];

int main() {
    cin >> n >> x;

    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];

    for (int i = 0; i <= x; i++) {
        if (a[0] <= i) dp[0][i] = b[0];
    }

    // can be done in 1d dp (check WLi sol)
    // basically we don't need to store last row as soon as we updae
    // our current row
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= x; ++j) {
            ll p = 0, q = 0;

            p = dp[i - 1][j];
            if (j >= a[i]) {
                q = dp[i - 1][j - a[i]] + b[i];
            }
            dp[i][j] = max(p, q);
        }
    }

    cout << dp[n - 1][x];
}
