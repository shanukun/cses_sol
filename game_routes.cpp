#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5;

int n, m, a, b;

bool vis[mxN + 1];
int d[mxN + 1], p[mxN + 1], dp[mxN + 1];
vector<int> g[mxN + 1];

void dfs(int vt) {
    vis[vt] = true;
    for (int c : g[vt]) {
        if (!vis[c]) {
            dfs(c);
        }
        if (dp[c] + 1 > dp[vt]) {
            p[vt] = c;
            dp[vt] = dp[c] + 1;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        g[a].push_back(b);
    }

    memset(dp, 0xc0, sizeof(dp));
    dp[n] = 1;
    for (int i = 1; i <= n; ++i)
        if (!vis[i]) dfs(i);

    if (dp[1] > 0) {
        vector<int> ans;
        int mp = 1;

        while (mp) {
            ans.push_back(mp);
            mp = p[mp];
        }

        cout << ans.size() << "\n";
        for (int u : ans)
            cout << u << " ";

    } else
        cout << "IMPOSSIBLE";
}
