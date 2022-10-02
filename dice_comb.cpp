#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 1e6;
const int mod = 1e9 + 7;

int n;

int dp[mxN + 1];

int main() {
    cin >> n;
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 6; j++) {
            if (i - j < 0) continue;
            dp[i] = (dp[i] + dp[i - j]) % mod;
        }
    cout << dp[n] % mod << "\n";
}
