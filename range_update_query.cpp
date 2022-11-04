#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x << ":" << x << "\n";

#define int long long
#define ar array

const int mxN = 2e5 + 7;

int n, q, x[mxN], t[mxN * 4];
bool mark[mxN * 4];

void build(int v, int l, int r) {
    if (l == r) {
        t[v] = x[l];
    } else {
        int m = (r + l) / 2;
        build(2 * v, l, m);
        build(2 * v + 1, m + 1, r);
        t[v] = 0;
    }
}

void push(int v) {
    if (mark[v]) {
        t[v * 2] += t[v];
        t[v * 2 + 1] += t[v];
        mark[v] = false;
        mark[v * 2] = mark[v * 2 + 1] = true;
    }
}

int qry(int v, int l, int r, int ql) {
    if (l == r)
        return t[v];

    /* push(v); */
    int m = (r + l) / 2;
    if (ql <= m)
        return t[v] + qry(2 * v, l, m, ql);
    else
        return t[v] + qry(2 * v + 1, m + 1, r, ql);
}

void upd(int v, int l, int r, int val, int p1, int p2) {
    if (p1 > p2)
        return;
    if (l == p1 && r == p2) {
        t[v] += val;
        mark[v] = true;
    } else {
        /* push(v); */
        int m = (r + l) / 2;
        upd(2 * v, l, m, val, p1, min(m, p2));
        upd(2 * v + 1, m + 1, r, val, max(p1, m + 1), p2);
    }
}

int32_t main() {
    cin >> n >> q;
    for (int i = 0; i < n; ++i)
        cin >> x[i];

    build(1, 0, n - 1);

    while (q--) {
        int qt, a, b, u;
        cin >> qt;
        if (qt == 1) {
            cin >> a >> b >> u, --a, --b;
            upd(1, 0, n - 1, u, a, b);
        } else {
            cin >> a, --a;
            cout << qry(1, 0, n - 1, a) << "\n";
        }
    }
}
