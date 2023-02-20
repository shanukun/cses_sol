#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x << " " << x << "\n";

#define ll long long
#define ar array

const int mxN = 2e5 + 1;

int n, m, x[mxN], in[mxN], out[mxN];

vector<int> adj[mxN];
vector<int> et;

void dfs(int u, int p = -1) {
    et.push_back(x[u]);
    in[u] = et.size() - 1;
    for (int v : adj[u]) {
        if (v == p)
            continue;
        dfs(v, u);
    }
    et.push_back(x[u]);
    out[u] = et.size() - 1;
}
ll t[8 * mxN];

void build(int v, int l, int r) {
    if (l == r) {
        t[v] = et[l];
    } else {
        int m = (l + r) / 2;
        build(v * 2, l, m);
        build(v * 2 + 1, m + 1, r);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

void upd(int v, int pos, int val, int l, int r) {
    if (l == r) {
        t[v] = val;
    } else {
        int m = (l + r) / 2;
        if (pos <= m)
            upd(v * 2, pos, val, l, m);
        else
            upd(v * 2 + 1, pos, val, m + 1, r);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

ll qry(int v, int p, int q, int l, int r) {
    if (p > q)
        return 0;
    if (p == l && q == r)
        return t[v];
    int m = (l + r) / 2;
    return qry(v * 2, p, min(q, m), l, m) +
           qry(v * 2 + 1, max(p, m + 1), q, m + 1, r);
}

int32_t main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> x[i + 1];
    for (int i = 0, a, b; i < n - 1; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);
    build(1, 0, et.size() - 1);

    while (m--) {
        int qt, a, b;
        cin >> qt;
        if (qt == 1) {
            cin >> a >> b;
            upd(1, in[a], b, 0, et.size() - 1);
            upd(1, out[a], b, 0, et.size() - 1);
        } else {
            cin >> a;
            cout << qry(1, in[a], out[a], 0, et.size() - 1) / 2 << "\n";
        }
    }
}
