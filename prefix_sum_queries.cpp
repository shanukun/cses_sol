#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x << ":" << x << "\n";

#define int long long
#define ar array

const int mxN = 2e5 + 1, inf = -1e18;

int n, m, x[mxN], h[mxN];

int lz[mxN * 4], t[mxN * 4];

void push(int v) {
    lz[v * 2] += lz[v];
    lz[v * 2 + 1] += lz[v];
    t[v * 2] += lz[v];
    t[v * 2 + 1] += lz[v];
    lz[v] = 0;
}

void build(int v, int l = 0, int r = n) {
    if (l == r) {
        t[v] = h[l];
    } else {
        int m = (l + r) / 2;
        build(v * 2, l, m);
        build(v * 2 + 1, m + 1, r);
        t[v] = max(t[v * 2], t[v * 2 + 1]);
    }
}

void upd(int v, int val, int p, int q, int l = 0, int r = n) {
    if (p > q) {
        return;
    }
    if (l == p && q == r) {
        t[v] += val;
        lz[v] += val;
    } else {
        push(v);
        int m = (l + r) / 2;
        upd(v * 2, val, p, min(q, m), l, m);
        upd(v * 2 + 1, val, max(p, m + 1), q, m + 1, r);
        t[v] = max(t[v * 2], t[v * 2 + 1]);
    }
}
int qry(int v, int p, int q, int l = 0, int r = n) {
    if (p > q) {
        return inf;
    }
    if (l == p && q == r) {
        return t[v];
    } else {
        push(v);
        int m = (l + r) / 2;
        return max(qry(v * 2, p, min(q, m), l, m),
                   qry(v * 2 + 1, max(p, m + 1), q, m + 1, r));
    }
}

int32_t main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> x[i], h[i] = x[i] + h[i - 1];
    build(1, 0, n);

    for (int i = 0; i < m; ++i) {
        int qt, a, b;
        cin >> qt >> a >> b;
        if (qt == 1) {
            upd(1, b - x[a], a, n);
            x[a] = b;
        } else {
            cout << max(0LL, qry(1, a, b) - qry(1, a - 1, a - 1)) << "\n";
        }
    }
}
