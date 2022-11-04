#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define pii pair<int, int>
#define ar array

const int mxN = 1e5 + 10, inf = 1e9 + 7;

int n, m, u, v;
vector<pair<int, int>> g[mxN];
vector<int> lvl(mxN, inf);

int bfs(int vt) {
    deque<int> q;
    q.push_back(vt);
    lvl[vt] = 0;

    while (!q.empty()) {
        int tn = q.front();
        q.pop_front();

        for (pii c : g[tn]) {
            if (lvl[tn] + c.ss < lvl[c.ff]) {
                lvl[c.ff] = lvl[tn] + c.ss;
                if (c.ss)
                    q.push_back(c.ff);
                else
                    q.push_front(c.ff);
            }
        }
    }
    return lvl[n] == inf ? -1 : lvl[n];
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        if (u == v) continue;
        g[u].push_back({v, 0});
        g[v].push_back({u, 1});
    }

    cout << bfs(1);
}

