#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

bool comp(pair<pii, int> a, pair<pii, int> b) {
    if (a.first.first == b.first.first) return a.first.second > b.first.second;
    return a.first.first < b.first.first;
}

int32_t main() {
    int n;
    cin >> n;
    vector<pair<pii, int>> v;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({{a, b}, i});
    }
    sort(v.begin(), v.end(), comp);

    int fa = INT_MAX;
    vector<int> ans1(n, 0);
    // contains
    for (int i = n - 1; i >= 0; i--) {
        if (v[i].first.second >= fa) {
            ans1[v[i].second] = 1;
        } else {
            fa = v[i].first.second;
        }
    }

    if (v[n - 1].first.second == v[n - 2].first.second &&
        v[n - 1].first.first == v[n - 2].first.first)
        ans1[n - 1] = 1;

    int mx = 0;
    vector<int> ans(n, 0);
    set<int> st2;
    // contained
    for (int i = 0; i < n; i++) {
        if (v[i].first.second <= mx) {
            ans[v[i].second] = 1;
        } else {
            mx = v[i].first.second;
        }
    }
    if (v[0].first.second == v[1].first.second &&
        v[0].first.first == v[1].first.first)
        ans[0] = 1;

    for (int i = 0; i < n; i++)
        cout << ans1[i] << " ";
    cout << endl;

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
}
