#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int a, d;
        cin >> a >> d;
        v.push_back({a, d});
    }
    sort(v.begin(), v.end());
    long long ans = 0;
    long long tt = 0;
    for (int i = 0; i < n; i++) {
        tt += v[i].first;
        ans += v[i].second - tt;
    }
    cout << ans << endl;
}
