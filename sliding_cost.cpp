#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(v) ((int)(v).size())

const int mxN = 2e5;
int n, k;

int32_t main() {
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
    ll sl = 0, sr = 0;
    for (int i = 0; i <= md; ++i)
        ls.insert(b[i]), sl += b[i].first;
    for (int i = md + 1; i < k; ++i)
        rs.insert(b[i]), sr += b[i].first;

    int i = 0, j = k - 1;
    while (j < n) {
        auto it = ls.end();
        --it;
        int med = it->first;

        cout << (med * sz(ls) - sl) + (sr - med * sz(rs)) << " ";

        if (ls.count(v[i]) > 0)
            ls.erase(v[i]), sl -= v[i].first;
        else if (rs.count(v[i]) > 0)
            rs.erase(v[i]), sr -= v[i].first;

        ++i, ++j;

        if (j >= n) break;

        if (v[j].first <= med)
            ls.insert(v[j]), sl += v[j].first;
        else
            rs.insert(v[j]), sr += v[j].first;

        if (sz(rs) > hf) {
            auto it = rs.begin();
            sr -= it->first;
            sl += it->first;
            ls.insert(*it);
            rs.erase(it);
        } else if (sz(rs) < hf) {
            auto it = ls.end();
            --it;
            sl -= it->first;
            sr += it->first;
            rs.insert(*it);
            ls.erase(it);
        }
    }
    cout << "\n";
}
