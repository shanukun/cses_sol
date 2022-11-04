#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5;

int n, e, u, v;

vector<int> g[mxN + 1];
int d[mxN + 1];

void dfs(int vt, int par) {
    for (int c : g[vt]) {
        if (c == par) continue;
        d[c] = d[vt] + 1;
        dfs(c, vt);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    int mdn = 0;
    for (int i = 1; i <= n; ++i)
        if (d[i] > d[mdn]) mdn = i, d[i] = 0;
    d[mdn] = 0;
    dfs(mdn, 0);
    for (int i = 1; i <= n; ++i)
        if (d[i] > d[mdn]) mdn = i;
    cout << d[mdn];
}
