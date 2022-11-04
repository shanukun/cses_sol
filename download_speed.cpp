#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x << ":" << x << "\n";

#define ll long long
#define ar array
const int mxN = 501;
const ll inf = 1e18 + 7;

int n, m, pr[mxN];
bool act[mxN];
ll cap[mxN][mxN], flow[mxN][mxN];
vector<int> adj[mxN];

void dfs(int u, ll rc) {
    if (u == n - 1) return;
    act[u] = 1;

    for (int v : adj[u]) {
        if (cap[u][v] - flow[u][v] <= 0 && act[v]) continue;

        ll nrc = min(rc, cap[u][v] - flow[u][v]);

        pr[v] = u;
        if (v == n - 1) {
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
    for (int i = 0, a, b, c; i < m; ++i) {
        cin >> a >> b >> c, --a, --b;
        if (cap[a][b] == 0) {
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        cap[a][b] += c;
    }
    dfs(0, inf);
    ll ans = 0;
    for (int i = 0; i < n; i++)
        ans += flow[i][n - 1];
    cout << ans;
}
