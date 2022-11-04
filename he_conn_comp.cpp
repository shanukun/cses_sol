#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5;

int n, e, u, v;

bool vis[mxN + 1];
vector<int> g[mxN + 1];

void dfs(int v) {
    vis[v] = true;
    for (int c : g[v]) {
        if (vis[c]) continue;
        dfs(c);
    }
}

int main() {
    cin >> n >> e;
    for (int i = 0; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
            cnt++;
        }
    }
    cout << cnt;
}
