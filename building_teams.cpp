#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5;

int n, m, a, b;

vector<int> g[mxN + 1];
bool vis[mxN + 1];
int team[mxN + 1];

bool bfs(int vt) {
    int tm = 1;
    queue<int> q;
    q.push(vt);
    vis[vt] = true;

    team[vt] = tm;
    while (!q.empty()) {
        int tn = q.front();
        q.pop();

        tm = 3 - team[tn];
        for (int c : g[tn]) {
            if (vis[c] && team[c] == 3 - tm) return false;
            if (vis[c]) continue;
            vis[c] = true;
            q.push(c);
            team[c] = tm;
        }
    }
    return true;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    bool isp = true;
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        isp &= bfs(i);
    }
    if (isp) {
        for (int i = 1; i <= n; ++i)
            cout << team[i] << " ";
    } else {
        cout << "IMPOSSIBLE";
    }
}
