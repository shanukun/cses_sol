#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

const int mxN = 1e5 + 1;

int n, m;
bool vis[mxN];
vector<int> adj1[mxN], adj2[mxN];

vector<int> top;
void dfs1(int v) {
    vis[v] = 1;
    for (int c : adj1[v]) {
        if (vis[c]) continue;
        dfs1(c);
    }
    top.push_back(v);
}

void dfs2(int v) {
    vis[v] = 1;
    for (int c : adj2[v]) {
        if (vis[c]) continue;
        dfs2(c);
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj1[a].push_back(b);
        adj2[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i)
        if (!vis[i]) dfs1(i);

    memset(vis, 0, sizeof(vis));

    reverse(top.begin(), top.end());
    int cnt = 0, prev;
    for (int i = 0; i < (int)top.size(); ++i)
        if (!vis[top[i]]) {
            dfs2(top[i]);
            cnt++;
            if (cnt > 1) {
                cout << "NO\n";
                cout << top[i] << " " << prev;
                return 0;
            } else
                prev = top[i];
        }
    cout << "YES";
}
