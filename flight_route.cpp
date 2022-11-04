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

int n, m, k;
ll d[mxN + 1];
int kt[mxN + 1];
vector<ar<int, 2>> g[mxN + 1];
vector<ll> ans;

void dijk(int src) {
    priority_queue<ar<ll, 2>, vector<ar<ll, 2>>, greater<ar<ll, 2>>> pq;
    pq.push({0, src});

    while (pq.size()) {
        ar<ll, 2> tn = pq.top();
        pq.pop();
        ll v = tn[1], w = tn[0];

        if (v == n) ans.push_back(w);

        if (kt[v] > k) continue;
        kt[v]++;

        for (auto c : g[v]) {
            d[c[0]] = w + c[1];
            pq.push({d[c[0]], c[0]});
        }
    }
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }
    dijk(1);
    sort(all(ans));
    for (int i = 0; i < k; ++i)
        cout << ans[i] << " ";
}

