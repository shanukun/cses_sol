#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x << ":" << x << "\n";

#define ll long long
#define ar array
const int mxN = 1007;
const ll inf = 1e18 + 7;

int n, m, k, pr[mxN];
vector<int> adj[mxN];

bool act[mxN];
ll cap[mxN][mxN], flow[mxN][mxN];

void dfs(int u, ll rc) {
    if (u == n + m + 1) return;
    act[u] = 1;

    for (int v : adj[u]) {
        if (cap[u][v] - flow[u][v] <= 0 && act[v]) continue;

        ll nrc = min(rc, cap[u][v] - flow[u][v]);

        pr[v] = u;
        if (v == n + m + 1) {
            int c = v;
            while (c) {
                flow[pr[c]][c] += nrc;
                flow[c][pr[c]] -= nrc;
                c = pr[c];
            }
        }
        dfs(v, nrc);
    }
    act[u] = 0;
}

int main() {
    cin >> n >> m;
    for (int i = 0, a, b; i < k; ++i) {
        cin >> a >> b;
        b = n + b;

        cap[0][a] = 1;
        cap[a][b] = 1;
        cap[b][n + m + 1] = 1;

        adj[0].push_back(a);
        adj[a].push_back(b);
        adj[b].push_back(n + m + 1);
    }
    dfs(0, inf);
    ll ans = 0;
    for (int i = 1; i <= m; i++)
        ans += flow[i][n + m + 1];
    cout << ans;
}
