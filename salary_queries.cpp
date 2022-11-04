#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x << ":" << x << "\n";

#define ll long long
#define ar array

const int mxN = 2e5 + 1;

int n, q, p[mxN], t[4 * mxN];

void build(int v = 1, int l = 0, int r = n - 1) {
    if (l == r)
        t[v] = p[l];
    else {
        build(v * 2);
        build(v * 2 + 1);
        t[v] = max(t[v * 2], t[v * 2 + 1]);
    }
}
void upd(int v, int val, int pos, int l = 0, int r = n - 1) {
    if (l == r) {
        t[v] = val;
    } else {
    }
}

int qry(int v, int ql, int qr, int l = 0, int r = n - 1) {
    ;
}

int32_t main() {
    cin >> n >> q;
    for (int i = 0; i < n; ++i)
        cin >> p[i];
    while (q--) {
        int qt, k, x;
        cin >> qt >> k >> x;
        if (qt == '?') {
            cout << qry(1, --k, --x) << "\n";
        } else {
            upd(1, k - 1, x);
        }
    }
}
