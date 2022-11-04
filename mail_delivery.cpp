#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x << ":" << x << "\n";

#define ll long long
#define ar array

const int mxN = 21, M = 1e9 + 7;

int dp[mxN][1 << mxN];
int n, m, lb;
vector<int> adj[mxN], pth;

int ro(int v, int mask) {
    if (v == n - 1 && mask == lb) return 1;
    if (v == n - 1) return 0;
    if (~dp[v][mask]) return dp[v][mask];

    int ans = 0;
    for (int c : adj[v]) {
        if (mask & (1 << c)) continue;
        ans = (ans + ro(c, mask ^ (1 << c))) % M;
    }
    return dp[v][mask] = ans;
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    lb = (1 << n) - 1;
    for (int i = 0, a, b; i < m; ++i) {
        cin >> a >> b, --a, --b;
        adj[a].push_back(b);
    }
    cout << ro(0, 1);
}
