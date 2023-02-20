#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << " " << x << "\n";

#define ll long long
#define ar array

const int mxN = 2e5 + 1;

int n, dp0[mxN], dp1[mxN];

vector<int> adj[mxN];

void dfs(int u, int p) {
    for (int v : adj[u]) {
        if (v == p)
            continue;
        dfs(v, u);
        dp0[u] += max(dp0[v], dp1[v]);
    }
    for (int v : adj[u])
        if (v != p)
            dp1[u] = max(dp1[u], dp0[v] + 1 + dp0[u] - max(dp0[v], dp1[v]));
}

int32_t main() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y, --x, --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(0, -1);
    cout << max(dp0[0], dp1[0]);
}
