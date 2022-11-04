#include <bits/stdc++.h>

using namespace std;

#define ll  long long
#define ff  first
#define ss  second
#define ar  array
#define pli pair<long long, int>
#define ar  array

const int mxN = 500;
const ll inf = 1e18;

int n, m, q;
ll g[mxN][mxN];

int main() {
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i == j)
                g[i][j] = 0;
            else
                g[i][j] = inf;

    for (int i = 0; i < m; i++) {
        ll x, y, wt;
        cin >> x >> y >> wt;
        --x, --y;
        g[x][y] = min(g[x][y], wt);
        g[y][x] = min(g[y][x], wt);
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        --a, --b;

        if (g[a][b] == inf)
            cout << -1;
        else
            cout << g[a][b];
        cout << "\n";
    }
}
