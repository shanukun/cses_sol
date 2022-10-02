#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 1e6, M = 1e9 + 7;

int n, x;
int a[mxN];

vector<ll> dp(mxN + 1, -1);

int main() {
    cin >> n >> x;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    dp[0] = 0;
    for (int i = 1; i <= x; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i - a[j] < 0) continue;
            if (dp[i] != -1 && dp[i - a[j]] != -1)
                dp[i] = min(dp[i - a[j]] + 1, dp[i]);
            else if (dp[i - a[j]] != -1)
                dp[i] = dp[i - a[j]] + 1;
        }
    }
    cout << dp[x];
}
