#include <bits/stdc++.h>
using namespace std;
int32_t main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int e, l;
        cin >> e >> l;
        v.push_back({e, 1});
        v.push_back({l, -1});
    }
    sort(v.begin(), v.end());

    int cnt = 0, ans = 0;

    for (int i = 0; i < 2 * n; i++) {
        cnt += v[i].second;
        ans = max(ans, cnt);
    }
    cout << ans << endl;
}
