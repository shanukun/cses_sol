#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxN = 5e2, M = 1e9 + 7;

int n;
ll dp[mxN * mxN];

int main() {
    cin >> n;
    ll ts = (n * (n + 1)) / 2;

    if (ts & 1) {
        cout << 0;
        return 0;
    }

    dp[0] = 1;
    for (int j = 1; j <= n; j++)
        for (int i = j * (j + 1) / 2; i >= j; i--)
            dp[i] = (dp[i] + dp[i - j]) % M;

    cout << (dp[ts / 2] * 500000004) % M;
}

