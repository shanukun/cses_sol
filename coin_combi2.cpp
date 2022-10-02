#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 1e6, M = 1e9 + 7;

int n, x;
int a[mxN];

int dp[mxN + 1];

int main() {
    cin >> n >> x;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    dp[0] = 1;
    for (int j = 0; j < n; ++j) {
        cout << "\n";
        for (int i = 1; i <= x; ++i) {
            if (i - a[j] < 0) continue;
            dp[i] = (dp[i] + dp[i - a[j]]) % M;
        }
    }
    cout << dp[x];
}
