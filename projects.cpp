#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ar array

const int mxN = 2e5;
const ll inf = 1e9;

int n;
ar<ll, 3> a[mxN];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i][1] >> a[i][0] >> a[i][2];
    sort(a, a + n);

    set<ar<ll, 2>> s;
    s.insert({0, 0});
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        auto it = s.lower_bound({a[i][1]});
        --it;
        ll sm = (*it)[1] + a[i][2];
        ans = max(ans, sm);
        s.insert({a[i][0], ans});
    }
    cout << ans;
}

