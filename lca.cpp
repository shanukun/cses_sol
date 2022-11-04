#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5;

int n, e, u, v;

vector<int> g[mxN + 1];
int mypar[mxN + 1];

void dfs(int vt, int par) {
    mypar[vt] = par;
    for (int c : g[vt]) {
        if (c == par) continue;
        dfs(c, vt);
    }
}

void path(vector<int> &p, int nd) {
    while (~mypar[nd]) {
        p.push_back(nd);
        nd = mypar[nd];
    }
    reverse(p.begin(), p.end());
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1);
    vector<int> p1, p2;
    path(p1, 7);
    path(p2, 2);
    int ans = 0;
    for (int i = 0; i < min((int)p1.size(), (int)p2.size()); ++i)
        if (p1[i] == p2[i])
            ans = p1[i];
        else
            break;
    cout << ans << "\n";
}
