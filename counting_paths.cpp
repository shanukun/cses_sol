#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x << " " << x << "\n";

#define ll long long
#define ar array

const int mxN = 2e5 + 1, mxB = 31;

int n, m, up[mxN][mxB], d[mxN], ans[mxN];
vector<int> adj[mxN];

void dfs(int v, int p) {
    up[v][0] = (~p ? p : 0);
    for (int u : adj[v]) {
        if (u == p)
            continue;
        d[u] = d[v] + 1;
        dfs(u, v);
    }
}

void dfs1(int u, int p) {
    for (int v : adj[u]) {
        if (v == p)
            continue;
        dfs1(v, u);
        ans[u] += ans[v];
    }
}

int jmp(int a, int k) {
    for (int i = mxB - 1; ~i; --i)
        if (k & (1 << i))
            a = up[a][i];

    return a;
}

int lca(int a, int b) {
    if (d[a] < d[b])
        swap(a, b);

    a = jmp(a, d[a] - d[b]);

    if (a == b)
        return a;

    for (int i = mxB - 1; ~i; --i)
        if (up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }

    return up[a][0];
}

int32_t main() {
    cin >> n >> m;
    for (int i = 0, a, b; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, -1);
    for (int i = 1; i < mxB; ++i) {
        for (int j = 1; j <= n; ++j) {
            up[j][i] = up[up[j][i - 1]][i - 1];
        }
    }

    while (m--) {
        int a, b;
        cin >> a >> b;
        ans[a]++, ans[b]++;
        int lc = lca(a, b);
        ans[lc]--;

        if (up[lc][0] != 0)
            ans[up[lc][0]]--;
    }

    dfs1(1, -1);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
}
