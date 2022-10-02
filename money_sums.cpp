#include <bits/stdc++.h>

#include <cmath>
using namespace std;

#define ll long long

const int mxN = 1e2, mxX = 1e5;

int n, a[mxN];

int dp[mxX + 1];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    dp[0] = 1;
    for (int i = 0; i < n; ++i)
        for (int j = mxX; j; --j)
            if (j >= a[i]) dp[j] |= dp[j - a[i]];

    vector<int> ans;
    for (int j = 1; j <= mxX; ++j)
        if (dp[j]) ans.push_back(j);
    cout << ans.size() << "\n";
    for (int z : ans)
        cout << z << " ";
}
