#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5;

int n, e, u, v;

vector<int> g[mxN + 1];
bool vis[mxN + 1];
int dis[mxN + 1];

void bfs(int vt) {
    queue<int> q;
    vis[vt] = true;
    dis[vt] = 0;
    q.push(vt);

    while (!q.empty()) {
        int tn = q.front();
        cout << tn << " " << dis[tn] << "\n";
        q.pop();
        for (int c : g[tn]) {
            if (vis[c]) continue;
            vis[c] = true;
            dis[c] += dis[tn] + 1;
            q.push(c);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bfs(1);
}
