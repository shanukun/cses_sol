#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5;

int n, m, a, b;

vector<int> g[mxN + 1];
bool vis[mxN + 1];
int pr[mxN + 1];

void dfs(int vt) {
    vis[vt] = true;
    for (int c : g[vt]) {
        if (vis[c] && pr[vt] && (int)g[c].size() > 0) {
            vector<int> ans;
            int u = vt;
            while (u && u ^ c) {
                ans.push_back(u);
                u = pr[u];
            }
            if (u == 0) {
                continue;
            } else {
                ans.push_back(c);
                ans.push_back(vt);
                cout << ans.size() << "\n";
                for (int i = int(ans.size()) - 1; ~i; --i)
                    cout << ans[i] << " ";
                exit(0);
            }
        }
        pr[c] = vt;
        dfs(c);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        /* g[b].push_back(a); */
    }

    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dfs(i);
        }
    }

    cout << "IMPOSSIBLE";
}
