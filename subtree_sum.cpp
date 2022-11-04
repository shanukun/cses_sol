#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5;

int n, e, q, u, v;

vector<int> g[mxN + 1];
int sts[mxN + 1], nen[mxN + 1];

void dfs(int vt, int par) {
    sts[vt] += vt;
    nen[vt] += vt % 2 == 0;
    for (int c : g[vt]) {
        if (c == par) continue;
        dfs(c, vt);
        sts[vt] += sts[c];
        nen[vt] += nen[c];
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
    for (int i = 1; i <= n; ++i) {
        cout << i << " ";
        cout << sts[i] << " ";
        cout << nen[i] << "\n";
    }
}
