#include <bits/stdc++.h>

#include <cmath>
using namespace std;

#define ll long long

const int mxN = 5e2;

int a, b;
ll dp[mxN + 1][mxN + 1];

int main() {
    cin >> a >> b;

    for (int i = 1; i <= mxN; ++i)
        dp[1][i] = i - 1;
    for (int i = 1; i <= mxN; ++i)
        dp[i][1] = i - 1;

    for (int i = 2; i <= mxN; ++i) {
        for (int j = 2; j <= mxN; ++j) {
            if (i == j) {
                dp[i][j] = 0;
                continue;
            }

            dp[i][j] = 1e9;

            for (int k = 1; k <= i / 2; k++)
                dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i - k][j]);

            for (int k = 1; k <= j / 2; k++)
                dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j - k]);
        }
    }
    cout << dp[a][b];
}
