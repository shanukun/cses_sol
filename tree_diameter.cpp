#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x << " " << x << "\n";

#define ll long long
#define ar array

const int mxN = 2e5 + 1;

int n, d[mxN];
vector<int> adj[mxN];

void dfs(int u, int p) {
    for (int v : adj[u]) {
        if (v == p)
            continue;
        d[v] = d[u] + 1;
        dfs(v, u);
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
    int j = 0;

    for (int i = 0; i < n; i++) {
        if (d[j] < d[i])
            j = i;
    }
    d[j] = 0;
    dfs(j, -1);
    j = 0;
    for (int i = 0; i < n; i++)
        if (d[j] < d[i]) {
            j = i;
        }
    cout << d[j];
}
