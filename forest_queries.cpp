#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x << ":" << x << "\n";

#define ll long long
#define ar array

const int mxN = 1001, mxQ = 2e5 + 1;

int n, q, m[mxN][mxN];
char g[mxN][mxN];

int32_t main() {
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> g[i][j];
            m[i + 1][j + 1] =
                m[i][j + 1] + m[i + 1][j] - m[i][j] + (g[i][j] == '*');
        }
    }
    while (q--) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << m[x2][y2] + m[x1 - 1][y1 - 1] - m[x2][y1 - 1] - m[x1 - 1][y2]
             << "\n";
    }
}
