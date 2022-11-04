#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5;

int n, m, a, b;

vector<int> g[mxN + 1];
bool vis[mxN + 1];
int pth[mxN + 1];

void bfs(int vt) {
    queue<int> q;
    q.push(vt);
    vis[vt] = true;
    while (!q.empty()) {
        int tn = q.front();
        q.pop();

        for (int c : g[tn]) {
            if (vis[c]) continue;
            vis[c] = true;
            q.push(c);
            pth[c] = tn;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    bfs(1);
    if (vis[n]) {
        vector<int> ans;
        while (n) {
            ans.push_back(n);
            n = pth[n];
        }
        cout << ans.size() << "\n";
        reverse(ans.begin(), ans.end());
        for (int comp : ans)
            cout << comp << " ";
    } else
        cout << "IMPOSSIBLE";
}
