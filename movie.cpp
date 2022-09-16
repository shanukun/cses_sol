#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        v.push_back({e, s});
    }
    sort(v.begin(), v.end());
    int ans = 1;
    int cur = 0;
    for (int i = 1; i < n; i++) {
        if (v[i].second >= v[cur].first) {
            cur = i;
            ans++;
        }
    }
    cout << ans << endl;
}
