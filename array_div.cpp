#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << x << "\n"
#define ll long long
#define ar array

const int mxN = 2e5;
int n, k;
int a[mxN];

bool cm(ll m) {
    ll ts = 0;
    int cnt = 1;
    for (int i = 0; i < n; i++) {
        ts += a[i];
        if (ts > m) {
            ts = a[i];
            cnt++;
        }
    }

    return cnt <= k;
}

int main() {
    cin >> n >> k;
    int ts = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i], ts = max(ts, a[i]);

    ll lo = ts, hi = 1e18;
    while (hi - lo > 1) {
        ll mid = lo + (hi - lo) / 2;
        if (cm(mid)) {
            hi = mid;
        } else
            lo = mid + 1;
    }
    if (cm(lo))
        cout << lo;
    else
        cout << hi;
    cout << "\n";
}
