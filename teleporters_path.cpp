#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x << ":" << x << "\n";

#define ll long long
#define ar array

const int mxN = 1e5 + 1, mxM = 2e5 + 1;

int n, m, sn[mxM], en[mxM];
bool mark[mxM];
vector<int> adj[mxN], pth;

void dfs(int v) {
    while (adj[v].size()) {
        int u = adj[v].back();
        adj[v].pop_back();

        if (mark[u]) continue;
        mark[u] = 1;

        dfs(v ^ sn[u] ^ en[u]);
        pth.push_back(v);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> sn[i] >> en[i], --sn[i], --en[i];
        adj[sn[i]].push_back(i);
        adj[en[i]].push_back(i);
    }
    for (int i = 0; i < n; i++)
        if (adj[i].size() & 1) {
            cout << "IMPOSSIBLE";
            return 0;
        }

    pth.push_back(0);
    dfs(0);
    if ((int)pth.size() != m + 1) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    for (int x : pth)
        cout << x + 1 << " ";
}
