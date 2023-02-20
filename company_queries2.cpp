#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x << " " << x << "\n";

#define int long long
#define ar array

const int mxN = 2e5 + 1, mxB = 31;

int n, m, up[mxN][mxB], d[mxN];
vector<int> adj[mxN];

void dfs(int v) {
    for (int u : adj[v]) {
        d[u] = d[v] + 1;
        dfs(u);
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
    for (int i = 2; i <= n; i++) {
        cin >> up[i][0];
        adj[up[i][0]].push_back(i);
    }

    dfs(1);

    for (int j = 1; j < mxB; ++j)
        for (int i = 1; i <= n; ++i)
            up[i][j] = up[up[i][j - 1]][j - 1];

    while (m--) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << "\n";
    }
}
