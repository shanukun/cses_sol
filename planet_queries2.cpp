#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn = 2e5 + 7;

int n, a, b, q;

bool vis[mxn], act[mxn];

int t[mxn], mark[mxn], d[mxn], mec[mxn];

vector<int> cyc;

void dfs(int v) {
    vis[v] = true;
    act[v] = 1;

    if (act[t[v]]) {
        int c = t[v];
        mark[c] = mark[v] = 1;
        while (c ^ v) {
            mark[c] = 1;
            cyc.push_back(c);
            c = t[c];
        }
        cyc.push_back(v);
    } else if (!vis[t[v]]) {
        dfs(t[v]);
    }
    act[v] = 0;
}

void dfs1(int v) {
    vis[v] = true;

    if (mark[v]) {
        mec[v] = v;
        return;
    } else if (!vis[t[v]]) {
        dfs1(t[v]);
    }
    d[v] = d[t[v]] + 1;
    mec[v] = mec[t[v]];
}

bool dfs2(int v, int c) {
    bool f = false;
    if (mark[t[v]]) return false;
    f |= dfs2(t[v], c);
    return f | (t[v] == c);
}

int main() {
    cin >> n >> q;

    for (int i = 1; i <= n; ++i)
        cin >> t[i];

    for (int i = 1; i <= n; ++i)
        if (!vis[i]) dfs(i);

    for (int i = 0; i < (int)cyc.size(); i++) {
        mark[cyc[i]] = i + 1;
    }

    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; ++i) {
        if (mark[i] == 0 && !vis[i]) dfs1(i);
    }

    /* for (int i = 1; i <= n; ++i) */
    /*     cerr << mark[i] << " "; */
    /* cerr << endl; */
    /* for (int i = 1; i <= n; ++i) */
    /*     cerr << mec[i] << " "; */
    /* cerr << endl; */

    /* for (int i = 1; i <= n; ++i) */
    /*     cerr << d[i] << " "; */
    /* cerr << endl; */

    auto circ = [](int x, int y, int z) {
        if (x <= y)
            return y - x;
        else
            return z - (x - y);
    };

    while (q--) {
        cin >> a >> b;

        int ans;
        int nums = cyc.size();
        if (mark[a] && mark[b]) {
            if (t[a] == a || t[b] == b)
                if (a == b)
                    ans = 0;
                else
                    ans = -1;
            else {
                int i = mark[a];
                int j = mark[b];
                int nums = cyc.size();
                ans = circ(i, j, nums);
            }

        } else if (mark[a]) {
            int i = mark[a];
            int j = mark[mec[b]];
            if (j)
                ans = d[b] + circ(i, j, nums);
            else
                ans = -1;

        } else if (mark[b]) {
            int i = mark[mec[a]];
            int j = mark[b];

            if (i)
                ans = d[a] + circ(i, j, nums);
            else
                ans = -1;

        } else {
            int i, j;
            if (mec[a] == mec[b] && d[a] != d[b]) {
                if (d[a] < d[b])
                    i = a, j = b;
                else
                    j = a, i = b;

                if (dfs2(i, j))
                    ans = d[j] - d[i];
                else
                    ans = -1;
            } else {
                ans = -1;
            }
        }
        if (a == b) ans = 0;
        cout << ans << "\n";
    }
}
