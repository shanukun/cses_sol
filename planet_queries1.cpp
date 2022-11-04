#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn = 2e5 + 7;

int n, x, k, q;

int up[mxn][30];

int main() {
    cin >> n >> q;

    for (int i = 1; i <= n; ++i)
        cin >> up[i][0];

    for (int i = 1; i < 30; ++i)
        for (int j = 1; j <= n; ++j)
            up[j][i] = up[up[j][i - 1]][i - 1];

    while (q--) {
        cin >> x >> k;
        for (int i = 30 - 1; ~i; --i)
            if (k & (1 << i)) x = up[x][i];

        cout << x << "\n";
    }
}
