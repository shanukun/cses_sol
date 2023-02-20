#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x << " " << x << "\n";

#define ll long long
#define ar array

const int mxN = 2e5 + 1, mxB = 21;

int n, m, up[mxN][mxB], d[mxN];
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

int jmp(int a, int b) {
    int ans = a;
    for (int j = mxB - 1; ~j; j--) {
        if (b & (1 << j)) {
            ans = up[ans][j];
        }
    }
    return ans;
}

int lca(int a, int b) {
    if (d[a] < d[b])
        swap(a, b);
    a = jmp(a, d[a] - d[b]);

    if (a == b)
        return a;

    for (int i = mxB - 1; ~i; --i) {
        if (up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
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

    for (int j = 1; j < mxB; ++j)
        for (int i = 1; i <= n; ++i)
            up[i][j] = up[up[i][j - 1]][j - 1];

    while (m--) {
        int a, b;
        cin >> a >> b;
        int lc = lca(a, b);
        cout << d[a] - d[lc] + d[b] - d[lc];
        cout << "\n";
    }
}
