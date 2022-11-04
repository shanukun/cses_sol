#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e3;
int n, m;
char g[mxN + 1][mxN + 1];

void dfs(int a, int b) {
    if (a < 0 || a >= n) return;
    if (b < 0 || b >= m) return;
    if (g[a][b] == '#') return;

    g[a][b] = '#';
    dfs(a + 1, b);
    dfs(a - 1, b);
    dfs(a, b + 1);
    dfs(a, b - 1);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> g[i][j];

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == '.') {
                cnt++;
                dfs(i, j);
            }
        }
    }
    cout << cnt;
}
