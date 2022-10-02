#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 2e5;
const ll inf = 1e9 + 1;

int n, x[mxN];
/* vector<int> dp(mxN + 1, mxN + 1); */
ll dp[mxN + 1];

int main() {
    memset(dp, inf, sizeof(dp));
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> x[i];

    dp[0] = -inf;
    for (int i = 0; i < n; i++) {
        /* int j = upper_bound(dp.begin(), dp.end(), x[i]) - dp.begin(); */
        int j = upper_bound(dp, dp + n, x[i]) - dp;
        if (dp[j - 1] < x[i] && x[i] < dp[j]) {
            dp[j] = x[i];
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (dp[i] < inf) ans = i;
    cout << ans;
}

