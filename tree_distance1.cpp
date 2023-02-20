#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x << " " << x << "\n";

#define ll long long
#define ar array

const int mxN = 2e5 + 1;

int n, d1[mxN], d2[mxN];
vector<int> adj[mxN];

void dfs(int u, int p, int d[mxN]) {
    for (int v : adj[u]) {
        if (v == p)
            continue;
        d[v] = d[u] + 1;
        dfs(v, u, d);
    }
}

int32_t main() {
    cin >> n;
    for (int i = 0, a, b; i < n - 1; i++) {
        cin >> a >> b, --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, -1, d1);

    int j = 0;
    for (int i = 0; i < n; i++) {
        if (d1[j] < d1[i])
            j = i;
    }
    d1[j] = 0;
    dfs(j, -1, d1);

    j = 0;
    for (int i = 0; i < n; i++) {
        if (d1[j] < d1[i]) {
            j = i;
        }
    }
    dfs(j, -1, d2);

    for (int i = 0; i < n; ++i)
        cout << max(d1[i], d2[i]) << " ";
}
