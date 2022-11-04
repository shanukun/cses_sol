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

const int mxN = 1e5;
const ll inf = 1e18;

int n, m;
ll d1[mxN + 1], d2[mxN + 1];
vector<ar<int, 2>> g1[mxN + 1], g2[mxN + 1];
void dijk(int src, ll d[mxN + 1], vector<ar<int, 2>> g[mxN]) {
    memset(d, 0x3f, sizeof(d1));
    set<ar<ll, 2>> pq;
    pq.insert({0, src});
    d[src] = 0;

    while (pq.size()) {
        ar<ll, 2> tn = *(pq.begin());
        pq.erase(tn);
        if (d[tn[1]] < tn[0]) continue;

        for (auto c : g[tn[1]]) {
            if (d[tn[1]] + c[1] < d[c[0]]) {
                d[c[0]] = d[tn[1]] + c[1];
                pq.insert({d[c[0]], c[0]});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        g1[a].push_back({b, c});
        g2[b].push_back({a, c});
    }
    dijk(1, d1, g1);
    dijk(n, d2, g2);
    ll mn = inf;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < (int)g1[i].size(); ++j) {
            mn = min(mn, d1[i] + g1[i][j][1] / 2 + d2[g1[i][j][0]]);
        }
    }
    cout << mn;
}

