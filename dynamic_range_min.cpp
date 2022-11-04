#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x << ":" << x << "\n";

#define int long long
#define ar array

const int mxN = 2e5 + 7, L = 20;

int n, q, x[mxN], t[mxN * 4];

void build(int v, int l, int r) {
    if (l == r)
        t[v] = x[l];
    else {
        int m = (r + l) / 2;
        build(2 * v, l, m);
        build(2 * v + 1, m + 1, r);
        t[v] = min(t[v * 2], t[v * 2 + 1]);
    }
}

int qry(int v, int l, int r, int ql, int qr) {
    if (ql > qr) return 1e18;
    if (l == ql && r == qr) return t[v];

    int m = (r + l) / 2;
    return min(qry(2 * v, l, m, ql, min(qr, m)),
               qry(2 * v + 1, m + 1, r, max(ql, m + 1), qr));
}

void upd(int v, int l, int r, int val, int p) {
    if (l == r)
        t[v] = val;
    else {
        int m = (r + l) / 2;
        if (p <= m)
            upd(2 * v, l, m, val, p);
        else
            upd(2 * v + 1, m + 1, r, val, p);

        t[v] = min(t[2 * v], t[v * 2 + 1]);
    }
}
int32_t main() {
    cin >> n >> q;
    for (int i = 0; i < n; ++i)
        cin >> x[i];
    /* memset(t, 0x3f, sizeof(t)); */
    build(1, 0, n - 1);

    while (q--) {
        int k, a, b;
        cin >> k >> a >> b, --a, --b;
        if (k == 1) {
            upd(1, 0, n - 1, ++b, a);
        } else {
            cout << qry(1, 0, n - 1, a, b) << "\n";
        }
    }
}
