#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll mx = 1e18;

bool chk(vector<int> &v, ll x, int n, int t) {
    ll tot = 0;
    for (int i = 0; i < n; i++) {
        ll p = x / v[i];
        if (tot > mx - p) {
            tot = mx;
        } else {
            tot += p;
        }
    }

    return tot >= t;
}

int32_t main() {
    int n, t;
    cin >> n >> t;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    ll lo = 1, hi = mx;
    while (hi - lo > 1) {
        ll mid = lo + (hi - lo) / 2;
        if (chk(v, mid, n, t))
            hi = mid;
        else
            lo = mid + 1;
    }

    ll ans;
    if (chk(v, lo, n, t))
        ans = lo;
    else
        ans = hi;

    cout << ans << endl;
}
