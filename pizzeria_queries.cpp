#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x << ":" << x << "\n";

#define ll long long
#define ar array

const int mxN = 2e5 + 1, inf = 2e9;

int n, m, x[mxN];
int t1[mxN * 4], t2[mxN * 4];
int h1[mxN], h2[mxN];

/* void push(int v, int t[mxN * 4]) { */
/*     lz[v * 2] += lz[v]; */
/*     lz[v * 2 + 1] += lz[v]; */
/*     t[v * 2] += lz[v]; */
/*     t[v * 2 + 1] += lz[v]; */
/*     lz[v] = 0; */
/* } */

void build(int t[mxN * 4], int h[mxN], int v, int l = 0, int r = n - 1) {
    if (l == r) {
        t[v] = h[l];
    } else {
        int m = (l + r) / 2;
        build(t, h, v * 2, l, m);
        build(t, h, v * 2 + 1, m + 1, r);
        t[v] = min(t[v * 2], t[v * 2 + 1]);
    }
}

void upd(int t[mxN * 4], int v, int val, int pos, int l = 0, int r = n - 1) {
    if (l == r) {
        t[v] = val;
    } else {
        int m = l + (r - l) / 2;

        if (pos <= m)
            upd(t, v * 2, val, pos, l, m);
        else
            upd(t, v * 2 + 1, val, pos, m + 1, r);
        t[v] = min(t[v * 2], t[v * 2 + 1]);
    }
}

int qry(int t[mxN * 4], int v, int p, int q, int l = 0, int r = n - 1) {
    if (p > q) {
        return inf;
    }
    if (l == p && q == r) {
        return t[v];
    } else {
        int m = (l + r) / 2;
        return min(qry(t, v * 2, p, min(q, m), l, m),
                   qry(t, v * 2 + 1, max(p, m + 1), q, m + 1, r));
    }
}

int32_t main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> x[i], h1[i] = x[i] - i, h2[i] = x[i] + i;
    build(t1, h1, 1);
    build(t2, h2, 1);

    for (int i = 0; i < m; ++i) {
        int qt, k, u;
        cin >> qt;
        if (qt == 1) {
            cin >> k >> u;
            upd(t1, 1, u - (k - 1), k - 1);
            upd(t2, 1, u + (k - 1), k - 1);
        } else {
            cin >> k;
            cout << min(qry(t1, 1, 0, k - 1) + (k - 1),
                        qry(t2, 1, k, n - 1) - (k - 1))
                 << "\n";
        }
    }
}
