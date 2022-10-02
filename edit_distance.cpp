#include <bits/stdc++.h>

#include <cmath>
using namespace std;

#define ll long long

const int mxN = 5e3;

string s1, s2;
ll dp[mxN][mxN];

int main() {
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();

    dp[0][0] = s1[0] != s2[0];
    for (int i = 1; i < m; i++)
        if (s2[i] != s1[0])
            dp[0][i] = dp[0][i - 1] + 1;
        else
            dp[0][i] = i;

    for (int i = 1; i < n; i++)
        if (s2[0] != s1[i])
            dp[i][0] = dp[i - 1][0] + 1;
        else
            dp[i][0] = i;

    // try to loose upper two loops
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (s1[i] == s2[j]) {
                dp[i][j] += dp[i - 1][j - 1];
            } else {
                ll x = min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]});
                dp[i][j] = x + 1;
            }
        }
    }

    cout << dp[n - 1][m - 1];
}
