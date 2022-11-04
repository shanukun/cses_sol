#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5;

int n, m, a, b;

bool vis[mxN + 1], act[mxN + 1];
vector<int> g[mxN + 1];

vector<int> ans;

void dfs(int vt) {
    vis[vt] = true;
    act[vt] = true;
    for (int c : g[vt]) {
        if (act[c]) {
            cout << "IMPOSSIBLE";
            exit(0);
        }
        if (vis[c]) continue;
        dfs(c);
    }
    act[vt] = false;
    ans.push_back(vt);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        g[a].push_back(b);
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i]) dfs(i);
    for (int i = (int)ans.size() - 1; ~i; --i)
        cout << ans[i] << " ";
}
