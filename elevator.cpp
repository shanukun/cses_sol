#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ar array

const int mxN = 20;
const ll inf = 1e9;

int n, x;
int w[mxN];

ar<int, 2> dp[1 << mxN];

int main() {
    cin >> n >> x;
    for (int i = 0; i < n; ++i)
        cin >> w[i];
    dp[0] = {1, 0};
    for (int i = 1; i < (1 << n); i++) {
        dp[i] = {n + 1, 0};
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                ar<int, 2> ch = dp[i ^ (1 << j)];
                if (ch[1] + w[j] <= x) {
                    ch[1] += w[j];
                } else {
                    ch[0]++;
                    ch[1] = w[j];
                }
                dp[i] = min(dp[i], ch);
            }
        }
    }
    cout << dp[(1 << n) - 1][0];
}

