#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x << " " << x << "\n";

#define int long long
#define ar array

const int mxN = 2e5 + 1;

int n, res[mxN], cnt[mxN];
vector<int> adj[mxN];

void dfs(int u, int p) {
    cnt[u] += 1;
    for (int v : adj[u]) {
        if (v == p)
            continue;
        dfs(v, u);
        cnt[u] += cnt[v];
        res[u] += cnt[v] + res[v];
    }
}
void dfs1(int u, int p) {
    if (p != -1) {
        res[u] = res[p] - cnt[u] + n - cnt[u];
    }
    for (int v : adj[u]) {
        if (v == p)
            continue;
        dfs1(v, u);
    }
}

int32_t main() {
    cin >> n;
    for (int i = 0, a, b; i < n - 1; i++) {
        cin >> a >> b, --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, -1);
    dfs1(0, -1);
    for (int i = 0; i < n; ++i)
        cout << res[i] << " ";
}
