#include <bits/stdc++.h>
using namespace std;

int n, x;

void dfs(vector<vector<int>> &v, int a, int b, int c, int ic) {
    int n = v.size();
    int m = v[0].size();
    if (a < 0 || a >= n) return;
    if (b < 0 || b >= m) return;
    if (v[a][b] != ic) return;

    v[a][b] = c;

    dfs(v, a + 1, b, c, ic);
    dfs(v, a - 1, b, c, ic);
    dfs(v, a, b + 1, c, ic);
    dfs(v, a, b - 1, c, ic);
}

vector<vector<int>> flood_fill(vector<vector<int>> &img, int sr, int sc,
                               int nc) {
    int ic = img[sr][sc];
    dfs(img, sr, sc, nc, ic);
    return img;
}

int main() {
    cin >> n;
    vector<vector<int>> v;
    for (int i = 0; i < n; ++i) {
        vector<int> t;
        for (int j = 0; j < n; ++j) {
            cin >> x;
            t.push_back(x);
        }
        v.push_back(t);
    }
    flood_fill(v, 0, 0, 2);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
}
