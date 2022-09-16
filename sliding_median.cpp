#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size())

const int mxN = 2e5;
int n, k;

int32_t main() {
#ifdef PRATHCP
    freopen("err", "w", stderr);
#endif
    cin >> n >> k;
    vector<pair<int, int>> v(n);
    vector<pair<int, int>> b(k);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first;
        v[i].second = i;
        if (i < k) b[i] = v[i];
    }
    sort(b.begin(), b.end());

    int hf = k / 2;
    set<pair<int, int>> ls, rs;
    int md = (k - 1) / 2;
    for (int i = 0; i <= md; ++i)
        ls.insert(b[i]);
    for (int i = md + 1; i < k; ++i)
        rs.insert(b[i]);

    int i = 0, j = k - 1;
    while (j < n) {
        auto it = ls.end();
        --it;
        int med = it->first;
        cout << med << " ";

        if (ls.count(v[i]) > 0)
            ls.erase(v[i]);
        else if (rs.count(v[i]) > 0)
            rs.erase(v[i]);

        ++i, ++j;

        if (j >= n) break;

        if (v[j].first <= med)
            ls.insert(v[j]);
        else
            rs.insert(v[j]);
        if (sz(rs) > hf) {
            auto it = rs.begin();
            ls.insert(*it);
            rs.erase(it);
        } else if (sz(rs) < hf) {
            auto it = ls.end();
            --it;
            rs.insert(*it);
            ls.erase(it);
        }
    }
    cout << "\n";
}
