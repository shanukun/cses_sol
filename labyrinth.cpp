#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define pii pair<int, int>
#define ar array

const int mxN = 1e3;

int n, m;
char g[mxN][mxN];
int dis[mxN][mxN];
int pth[mxN][mxN];

const int di[4] = {1, -1, 0, 0}, dj[4] = {0, 0, 1, -1},
          dc[4] = {'D', 'U', 'R', 'L'};

void bfs(int a, int b) {
    queue<pii> q;
    q.push({a, b});
    dis[a][b] = 0;
    g[a][b] = '#';

    while (!q.empty()) {
        pii tn = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int u = tn.ff + di[i];
            int v = tn.ss + dj[i];

            if (u < 0 || u >= n || v < 0 || v >= m) continue;
            if (g[u][v] == '#') continue;

            g[u][v] = '#';
            dis[u][v] = dis[tn.ff][tn.ss] + 1;
            pth[u][v] = i;

            q.push({u, v});
        }
    }
}

int main() {
    cin >> n >> m;
    pii ap, bp;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];
            if (g[i][j] == 'A') ap = {i, j};
            if (g[i][j] == 'B') bp = {i, j};
        }
    }

    bfs(ap.ff, ap.ss);

    if (dis[bp.ff][bp.ss] > 0) {
        cout << "YES\n";
        string t;
        while (bp.ff ^ ap.ff || bp.ss ^ ap.ss) {
            t.push_back(dc[pth[bp.ff][bp.ss]]);
            int cc = pth[bp.ff][bp.ss] ^ 1;
            bp.ff += di[cc];
            bp.ss += dj[cc];
        }
        cout << t.size() << "\n";
        reverse(t.begin(), t.end());
        cout << t << "\n";
    } else
        cout << "NO\n";
}
