#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 5e3, M = 1e9 + 7;

int n, x[mxN];
ll dp[mxN][mxN];

int main() {
    cin >> n;
    ll ts = 0;
    for (int i = 0; i < n; i++)
        cin >> x[i], ts += x[i], dp[i][i] = x[i];

    for (int i = n - 1; ~i; --i) {
        for (int j = i + 1; j < n; ++j) {
            dp[i][j] = max(x[i] - dp[i + 1][j], x[j] - dp[i][j - 1]);
        }
    }
    cout << (ts + dp[0][n - 1]) / 2;
}

