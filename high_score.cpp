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
const ll inf = 1e17, ninf = -inf;

int n, m;
ll d[mxN + 1];
vector<ar<int, 3>> ed;

int main() {
    memset(d, 0x3f, sizeof(d));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        ed.push_back({a, b, -c});
    }
    d[1] = 0;
    for (int i = 2; i <= n; i++)
        d[i] = inf;
    for (int i = 0; i < n - 1; ++i)
        for (auto e : ed) {
            if (d[e[0]] == inf) continue;
            d[e[1]] = min(d[e[1]], d[e[0]] + e[2]);
            d[e[1]] = max(d[e[1]], ninf);
        }

    for (int i = 0; i < n - 1; ++i) {
        for (auto e : ed) {
            if (d[e[0]] == inf) continue;
            d[e[1]] = max(d[e[1]], ninf);
            if (d[e[0]] + e[2] < d[e[1]]) d[e[1]] = ninf;
        }
    }
    cout << (d[n] == ninf ? -1 : -d[n]);
}
