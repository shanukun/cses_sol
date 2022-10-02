#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 1e5, mxM = 1e2, M = 1e9 + 7;

int n, m;
int a[mxN];
int dp[mxN + 1][mxM + 1];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    if (a[0] == 0)
        for (int i = 0; i <= m; ++i)
            dp[0][i]++;
    else
        dp[0][a[0]]++;

    for (int i = 1; i < n; i++) {
        if (a[i] == 0) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % M;
                if (j - 1 >= 1) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % M;
                if (j + 1 <= m) dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % M;
            }
        } else {
            dp[i][a[i]] = (dp[i][a[i]] + dp[i - 1][a[i]]) % M;
            if (a[i] - 1 >= 1)
                dp[i][a[i]] = (dp[i][a[i]] + dp[i - 1][a[i] - 1]) % M;
            if (a[i] + 1 <= m)
                dp[i][a[i]] = (dp[i][a[i]] + dp[i - 1][a[i] + 1]) % M;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= m; i++)
        ans = (ans + dp[n - 1][i]) % M;
    cout << ans;
}
