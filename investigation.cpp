#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn = 1e5 + 7, M = 1e9 + 7;

int n, m;

ll d[mxn], mif[mxn], mxf[mxn], nor[mxn];
bool vis[mxn];
vector<ar<int, 2>> adj[mxn];

void dijk(int s) {
    memset(d, 0x3f, sizeof(d));

    priority_queue<ar<ll, 3>, vector<ar<ll, 3>>, greater<ar<ll, 3>>> q;
    q.push({0, s, 0});
    d[s] = 0;
    nor[s] = 1;

    while (q.size()) {
        ll u = q.top()[1];
        ll w = q.top()[0];
        ll nf = q.top()[2];
        q.pop();

        if (vis[u]) continue;
        vis[u] = true;

        for (auto c : adj[u]) {
            if (w + c[1] < d[c[0]]) {
                d[c[0]] = w + c[1];
                q.push({d[c[0]], c[0], nf + 1});
                mif[c[0]] = mif[u] + 1;
                mxf[c[0]] = mxf[u] + 1;
                nor[c[0]] = nor[u];

            } else if (w + c[1] == d[c[0]]) {
                mif[c[0]] = min(mif[c[0]], mif[u] + 1);
                mxf[c[0]] = max(mxf[c[0]], mxf[u] + 1);
                nor[c[0]] = (nor[c[0]] + nor[u]) % M;
                q.push({d[c[0]], c[0], nf + 1});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    dijk(1);
    cout << d[n] << " " << nor[n] << " ";
    cout << mif[n] << " " << mxf[n] << " ";
}
