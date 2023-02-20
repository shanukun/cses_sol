#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x << " " << x << "\n";

#define int long long
#define ar array

const int mxN = 2e5 + 1, mxB = 30;

int n, m, up[mxN][mxB];

int32_t main() {
    cin >> n >> m;
    for (int i = 2; i <= n; i++) {
        cin >> up[i][0];
    }
    for (int j = 1; j < mxB; ++j) {
        for (int i = 1; i <= n; ++i) {
            up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }
    while (m--) {
        int a, b;
        cin >> a >> b;
        int ans = a;
        for (int j = mxB - 1; ~j; j--) {
            if (b & (1 << j)) {
                ans = up[ans][j];
            }
        }
        cout << (ans == 0 ? -1 : ans) << "\n";
    }
}
