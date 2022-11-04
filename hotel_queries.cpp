#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x << ":" << x << "\n";

#define ll long long
#define ar array

const int mxN = 2e5 + 1;

int n, m, h[mxN];

struct {
    int mx, ind;
} t[4 * mxN];

void build(int v, int l, int r) {
    if (l == r) {
        t[v].mx = h[l];
        t[v].ind = l;
    } else {
        int m = (l + r) / 2;
        build(v * 2, l, m);
        build(v * 2 + 1, m + 1, r);
        if (t[v * 2].mx >= t[v * 2 + 1].mx)
            t[v] = t[v * 2];
        else
            t[v] = t[v * 2 + 1];
    }
}

void upd(int v, int l, int r, int val, int pos) {
    if (l == r) {
        t[v].mx -= val;
        t[v].ind = l;
    } else {
        int m = (l + r) / 2;
        if (pos <= m)
            upd(v * 2, l, m, val, pos);
        else
            upd(v * 2 + 1, m + 1, r, val, pos);

        if (t[v * 2].mx >= t[v * 2 + 1].mx) {
            t[v].mx = t[v * 2].mx;
            t[v].ind = t[v * 2].ind;
        } else {
            t[v].mx = t[v * 2 + 1].mx;
            t[v].ind = t[v * 2 + 1].ind;
        }
    }
}

int qry(int v, int l, int r, int p, int q, int val) {
    if (p > r || l > q)
        return -1;

    if (p <= l && r <= q) {
        if (t[v].mx < val)
            return -1;

        while (l != r) {
            int mid = l + (r - l) / 2;
            if (t[v * 2].mx >= val) {
                v = v * 2;
                r = mid;
            } else {
                v = v * 2 + 1;
                l = mid + 1;
            }
        }
        return l;
    }
    int m = (l + r) / 2;
    int res = qry(v * 2, l, m, p, q, val);
    if (~res)
        return res;
    return qry(v * 2 + 1, m + 1, r, p, q, val);
}

int32_t main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> h[i];
    build(1, 0, n - 1);

    for (int i = 0; i < m; ++i) {
        int a, in;
        cin >> a;
        in = qry(1, 0, n - 1, 0, n - 1, a);
        cout << in + 1 << " ";
        if (~in)
            upd(1, 0, n - 1, a, in);
    }
}
