#include <bits/stdc++.h>

using namespace std;

#define ll     long long
#define ff     first
#define ss     second
#define ar     array
#define sz(v)  ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define endl   '\n'
#define pli    pair<long long, int>

const int mxN = 2.5e3;
const ll inf = 1e18;

int n, m;
int p[mxN + 1];
ll d[mxN + 1];
vector<ar<int, 3>> ed;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        ed.push_back({a, b, c});
    }
    bool f = false;
    int x;
    for (int i = 0; i < n; ++i) {
        f = false;
        for (auto e : ed) {
            if (d[e[0]] + e[2] < d[e[1]]) {
                d[e[1]] = min(-inf, d[e[0]] + e[2]);
                p[e[1]] = e[0];
                x = e[1];
                f = true;
            }
        }
    }

    if (f) {
        for (int i = 0; i < n; ++i)
            x = p[x];

        int y = x;

        vector<int> pth;
        for (int c = y;; c = p[c]) {
            pth.push_back(c);
            if (c == y && pth.size() > 1) break;
        }

        cout << "YES\n";
        for (int i = (int)pth.size() - 1; ~i; --i)
            cout << pth[i] << " ";
    } else {
        cout << "NO";
    }
}
