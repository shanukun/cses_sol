#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

const int mxN = 1e5 + 1;

int n, m, k[mxN], mark[mxN];
bool vis[mxN];
vector<int> adj1[mxN], adj2[mxN], adj3[mxN];
ll dp[mxN];
unordered_map<int, ll> mp;

vector<int> top;
void dfs1(int v) {
    vis[v] = 1;
    for (int c : adj1[v]) {
        if (vis[c]) continue;
        dfs1(c);
    }
    top.push_back(v);
}

void dfs2(int v, int m) {
    vis[v] = 1;
    mark[v] = m;
    for (int c : adj2[v]) {
        if (vis[c]) continue;
        dfs2(c, m);
    }
}
void dfs3(int v) {
    vis[v] = 1;
    for (int c : adj1[v]) {
        if (!vis[c]) dfs3(c);

        if (mark[c] != mark[v]) {
            adj3[mark[v]].push_back(mark[c]);
        }
    }
}

void dfs4(int v) {
    vis[v] = 1;
    for (int c : adj3[v]) {
        if (!vis[c]) {
            dfs4(c);
        }
        dp[v] = max(dp[v], dp[c] + mp[v]);
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> k[i];

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj1[a].push_back(b);
        adj2[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i)
        if (!vis[i]) dfs1(i);

    memset(vis, 0, sizeof(vis));
    reverse(top.begin(), top.end());
    int cnt = 0;
    for (int i = 0; i < (int)top.size(); ++i)
        if (!vis[top[i]]) {
            cnt++;
            dfs2(top[i], cnt);
        }

    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; ++i)
        if (!vis[i]) dfs3(i);

    for (int i = 1; i <= n; i++)
        mp[mark[i]] += k[i - 1];

    /* for (int i = 1; i <= cnt; ++i) { */
    /*     cerr << i << ":"; */
    /*     for (int x : adj3[i]) */
    /*         cerr << x << " "; */
    /*     cerr << "\n"; */
    /* } */
    for (int i = 1; i <= cnt; ++i)
        dp[i] = mp[i];
    memset(vis, 0, sizeof(vis));
    ll ans = 0;
    for (int i = 1; i <= cnt; ++i)
        if (!vis[i]) {
            dfs4(i);
            ans = max(ans, dp[i]);
        }

    cout << ans;
}
