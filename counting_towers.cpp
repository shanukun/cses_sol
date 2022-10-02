#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 1e6 + 1, M = 1e9 + 7;

int t, n;
ll dp[mxN][8];

int main() {
    for (int i = 0; i < mxN; ++i)
        dp[0][i] = 1;

    for (int i = 1; i < mxN; i++) {
        for (int j = 0; j < 8; ++j) {
            if (j == 0 || j == 2 || j == 3 || j == 4 || j == 5) {
                dp[i][j] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][3] +
                            dp[i - 1][4] + dp[i - 1][5]) %
                           M;
            } else {
                dp[i][j] = (dp[i - 1][2] + dp[i - 1][6] + dp[i - 1][7]) % M;
            }
        }
    }
    cin >> t;
    while (t--) {
        cin >> n;
        cout << (dp[n - 1][2] + dp[n - 1][6]) % M << "\n";
    }
}
