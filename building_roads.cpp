#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5;

int n, m, a, b;

vector<int> g[mxN + 1];
bool vis[mxN + 1];

void dfs(int vt) {
    vis[vt] = true;
    for (int c : g[vt]) {
        if (vis[c]) continue;
        dfs(c);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int cnt = 0;
    vector<int> con_comp;
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        con_comp.push_back(i);
        cnt++;
        dfs(i);
    }
    cout << cnt - 1 << "\n";
    for (int i = 1; i < (int)con_comp.size(); ++i)
        cout << con_comp[i - 1] << " " << con_comp[i] << "\n";
}
