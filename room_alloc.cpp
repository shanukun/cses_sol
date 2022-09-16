#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

int main() {
    int n;
    cin >> n;

    vector<pair<int, pii>> v;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, {1, i}});
        v.push_back({y + 1, {-1, i}});
    }

    sort(v.begin(), v.end());

    set<int> an;
    vector<int> ans(n);
    int nn = 1;
    for (int i = 0; i < 2 * n; i++) {
        if (v[i].second.first == 1) {
            if (!an.empty()) {
                auto it = an.begin();
                ans[v[i].second.second] = *it;
                an.erase(it);
            } else {
                ans[v[i].second.second] = nn++;
            }
        } else {
            an.insert(ans[v[i].second.second]);
        }
    }

    cout << nn - 1 << endl;
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
}
