#include <bits/stdc++.h>

using namespace std;

#define ll     long long
#define ff     first
#define ss     second
#define ar     array
#define sz(v)  ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define endl   '\n'

// clang-format off
#ifdef PRATHCP
#define debug(x) cerr << #x << " : "; _print(x); cerr << endl;
#else
#define debug(x);
#endif

void _print(int a) { cerr << a; }
void _print(string a) { cerr << a; }

template <class T, class V> void _print(pair<T, V> p);
template <class T> void _print(set<T> s1);
template <class T> void _print(vector<T> v1);
template <class T, class V> void _print(map<T, V> m1);
template <class T, class V> void _print(pair<T, V> p) { cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}"; }
template <class T> void _print(array<T, 2> p) { cerr << "{"; _print(p[0]); cerr << ","; _print(p[1]); cerr << "}"; }
template <class T> void _print(set<T> s1) { cerr << "["; for (T i : s1) { _print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(vector<T> v1) { cerr << "["; for (T i : v1) { _print(i); cerr << " ";} cerr << "\b]"; }
template <class T, class V> void _print(map<T, V> m1) { cerr << "["; for (auto x : m1) { _print(x); cerr << " "; } cerr << "\b]"; }
// clang-format on
/* ------------------------------------------------------------------------- */
#define pii pair<int, int>
#define ar  array

const int mxN = 1e3;
const int inf = 1e9 + 7;

int n, m;
char g[mxN][mxN];
bool vis[mxN][mxN];
int d1[mxN][mxN], d2[mxN][mxN], p1[mxN][mxN], p2[mxN][mxN];

const int di[4] = {1, -1, 0, 0}, dj[4] = {0, 0, 1, -1},
          dc[4] = {'D', 'U', 'R', 'L'};

bool e(int a1, int b1) {
    return a1 < 0 || b1 < 0 || a1 >= n || b1 >= m || vis[a1][b1];
}

void bfs(vector<ar<int, 2>> &v, int p[mxN][mxN], int d[mxN][mxN]) {
    queue<ar<int, 2>> q;
    memset(vis, false, sizeof(vis));
    memset(d, inf, sizeof(d1));
    for (auto el : v) {
        q.push(el);
        vis[el[0]][el[1]] = true;
        d[el[0]][el[1]] = 0;
    }

    while (!q.empty()) {
        ar<int, 2> ps = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int u = ps[0] + di[i];
            int v = ps[1] + dj[i];

            if (e(u, v)) continue;
            if (g[u][v] == '#') continue;

            d[u][v] = min(d[u][v], d[ps[0]][ps[1]] + 1);
            p[u][v] = i;
            vis[u][v] = true;
            q.push({u, v});
        }
    }
}
int main() {
    cin >> n >> m;

    int ai, aj;
    vector<pii> boun;
    vector<ar<int, 2>> v1, v2;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];
            if (g[i][j] == 'M') v2.push_back({i, j});
            if (g[i][j] == 'A') v1.push_back({i, j}), ai = i, aj = j;
            if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
                if (g[i][j] == '.' || g[i][j] == 'A') boun.push_back({i, j});
        }
    }
    bfs(v1, p1, d1);
    bfs(v2, p2, d2);

    for (pii ed : boun) {
        int ei = ed.ff;
        int ej = ed.ss;
        if (d1[ei][ej] < d2[ei][ej]) {
            string t;
            while (ei ^ ai || ej ^ aj) {
                t.push_back(dc[p1[ei][ej]]);
                int nd = p1[ei][ej] ^ 1;
                ei += di[nd];
                ej += dj[nd];
            }

            cout << "YES\n";
            reverse(t.begin(), t.end());
            cout << t.size() << "\n";
            cout << t;
            exit(0);
        }
    }
    cout << "NO\n";
}
