#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x << " " << x << "\n";

#define ll long long
#define ar array

const int mxN = 2e5 + 7;

int n, m, x[mxN], ans[mxN];
int t[4 * mxN];

ar<int, 3> quer[mxN];
map<int, int> mp;

void upd(int v, int pos, int val, int l = 0, int r = n - 1) {
    if (l == r) {
        t[v] += val;
    } else {
        int m = (l + r) / 2;
        if (pos <= m)
            upd(v * 2, pos, val, l, m);
        else
            upd(v * 2 + 1, pos, val, m + 1, r);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}
int qry(int v, int p, int q, int l = 0, int r = n - 1) {
    if (p > q) {
        return 0;
    }
    if (l == p && r == q) {
        return t[v];
    } else {
        int m = (l + r) / 2;
        return qry(v * 2, p, min(q, m), l, m) +
               qry(v * 2 + 1, max(m + 1, p), q, m + 1, r);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> x[i];

    for (int i = 0; i < m; i++)
        cin >> quer[i][1] >> quer[i][0], quer[i][2] = i;

    sort(quer, quer + m);

    for (int i = 0, j = 0; i < n; i++) {
        if (mp.count(x[i])) {
            upd(1, mp[x[i]], -1);
        }
        mp[x[i]] = i;
        upd(1, i, 1);

        while (i + 1 == quer[j][0]) {
            ans[quer[j][2]] = qry(1, quer[j][1] - 1, quer[j][0] - 1);
            j++;
        }
    }

    for (int i = 0; i < m; ++i)
        cout << ans[i] << "\n";
}
