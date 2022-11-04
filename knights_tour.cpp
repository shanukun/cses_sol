#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x << ":" << x << "\n";
#define ll       long long
#define ar       array

int n, m, adj[8][8], di[8] = {2, 2, -2, -2, 1, -1, -1, 1},
                     dj[8] = {1, -1, 1, -1, 2, 2, -2, -2};

bool e(int i, int j) {
    return (i >= 0 && j >= 0 && j < 8 && i < 8) && (adj[i][j] == 0);
}

void display() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j)
            cout << adj[i][j] << " ";
        cout << "\n";
    }
}

int deg(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 8; ++i) {
        if (e(x + di[i], y + dj[i])) cnt++;
    }
    return cnt;
}

bool cmp(const ar<int, 2> a, const ar<int, 2> b) {
    return deg(a[0], a[1]) <= deg(b[0], b[1]);
}

void dfs(int i, int j, int cnt) {
    adj[i][j] = cnt;

    if (cnt == 64) {
        display();
        adj[i][j] = 0;
        exit(0);
    }

    vector<ar<int, 2>> p;
    for (int k = 0; k < 8; k++)
        if (e(i + di[k], j + dj[k])) p.push_back({i + di[k], j + dj[k]});

    sort(p.begin(), p.end(), cmp);
    for (auto x : p) {
        dfs(x[0], x[1], cnt + 1);
    }
    adj[i][j] = 0;
}

int main() {
    cin >> n >> m;
    dfs(--m, --n, 1);
}
