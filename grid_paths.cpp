#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 1e3, M = 1e9 + 7;

int n, x;
char a[mxN][mxN];
ll dp[mxN + 1][mxN + 1];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    if (a[0][0] == '*') {
        cout << 0;
        return 0;
    }
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; ++j) {
            if (i == 0 && j == 0) continue;
            if (a[i][j] == '*') continue;

            if (i - 1 >= 0 && a[i - 1][j] != '*')
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % M;
            if (j - 1 >= 0 && a[i][j - 1] != '*')
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % M;
        }
    }
    cout << dp[n - 1][n - 1] % M;
}
