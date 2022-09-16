#include <bits/stdc++.h>
using namespace std;

#define int long long
int32_t main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int ans = v[0];
    int cur = -1;
    for (int i = 0; i < n; i++) {
        if (cur < 0) {
            cur = v[i];
        } else {
            cur += v[i];
        }
        ans = max(ans, cur);
    }
    cout << ans << endl;
}
