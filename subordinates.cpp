#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << " " << x << "\n";

#define ll long long
#define ar array

const int mxN = 2e5 + 1;

int n, x, dp[mxN];

vector<int> adj[mxN];

void dfs(int u) {
    for (int v : adj[u]) {
        dfs(v);
        dp[u] += dp[v] + 1;
    }
}

int32_t main() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        cin >> x, --x;
        adj[x].push_back(i);
    }
    dfs(0);
    for (int i = 0; i < n; ++i)
        cout << dp[i] << " ";
}
