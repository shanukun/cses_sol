#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    int n;
    cin >> n;
    vector<int> v(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        ans += v[i];
    }
    ans++;
    sort(v.begin(), v.end());
    int cn = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] > cn + 1) {
            ans = cn + 1;
            break;
        } else {
            cn += v[i];
        }
    }
    cout << ans << endl;
}
