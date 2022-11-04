#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x << ":" << x << "\n";

#define int long long
#define ar array

const int mxN = 2e5 + 1, inf = 2e9;
int n, m, x[mxN];

struct Node {
    int sm, pr, su, mx;
};
Node t[mxN * 4];

void comb(int v) {
    int y = v * 2, z = v * 2 + 1;
    t[v].sm = t[y].sm + t[z].sm;
    t[v].pr = max(t[y].sm + t[z].pr, t[y].pr);
    t[v].su = max(t[z].sm + t[y].su, t[z].su);
    t[v].mx = max({t[z].pr + t[y].su, t[z].mx, t[y].mx});
}

void build(int v, int l = 0, int r = n - 1) {
    if (l == r) {
        t[v].sm = x[l];
        t[v].pr = t[v].su = t[v].mx = max(x[l], 0ll);
    } else {
        int m = (l + r) / 2;
        build(v * 2, l, m);
        build(v * 2 + 1, m + 1, r);
        comb(v);
    }
}

void upd(int v, int val, int pos, int l = 0, int r = n - 1) {
    if (l == r) {
        t[v].sm = val;
        t[v].pr = t[v].su = t[v].mx = max(val, 0ll);
    } else {
        int m = (l + r) / 2;
        if (pos <= m)
            upd(v * 2, val, pos, l, m);
        else
            upd(v * 2 + 1, val, pos, m + 1, r);

        comb(v);
    }
}

int32_t main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    build(1);
    while (m--) {
        int k, u;
        cin >> k >> u;
        upd(1, u, k - 1);
        cout << max(t[1].mx, 0ll) << "\n";
    }
}
