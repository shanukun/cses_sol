#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x << ":" << x << "\n";

#define ll long long
#define ar array

const int mxN = 15, mxM = 1 << 15;

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
        pth.push_back(u);
    }
}

int main() {
    cin >> n;
    if (n == 1) {
        cout << "01";
        return 0;
    }
    for (int i = 0; i < (1 << n); ++i) {
        sn[i] = i / 2;
        en[i] = i & ((1 << (n - 1)) - 1);
        adj[sn[i]].push_back(i);
    }
    dfs(0);
    for (int i = 0; i < (int)pth.size(); ++i)
        cout << pth[i] % 2;
    for (int i = 0; i < n - 1; ++i)
        cout << 0;
}
