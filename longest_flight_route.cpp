#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5, M = 1e9 + 7;

int n, m, a, b;

int dp[mxN + 1], vis[mxN + 1];
vector<int> g[mxN + 1];

void dfs(int vt) {
    vis[vt] = true;
    for (int c : g[vt]) {
        if (!vis[c]) {
            dfs(c);
        }
        dp[vt] = (dp[vt] + dp[c]) % M;
    }
}

void bfs(int v) {
    queue<int> q;
    q.push(v);
    vis[v] = true;
    dp[v] = 1;

    while (q.size()) {
        int u = q.front();
        q.pop();

        for (int c : g[u]) {
            cerr << c << " " << dp[u] << "\n";
            dp[c] = (dp[c] + dp[u]) % M;
            if (!vis[c]) q.push(c);
            vis[c] = true;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        g[a].push_back(b);
    }

    for (int i = 1; i <= n; ++i)
        if (!vis[i]) bfs(i);
    cout << dp[n] << "\n";
    for (int i = 1; i <= n; ++i)
        cerr << dp[i] << " ";
    cerr << "\n";

    memset(dp, 0, sizeof(dp));
    memset(vis, 0, sizeof(vis));
    dp[n] = 1;

    for (int i = 1; i <= n; ++i)
        if (!vis[i]) dfs(i);
    cout << dp[1];
    for (int i = 1; i <= n; ++i)
        cerr << dp[i] << " ";
    cerr << "\n";
}
