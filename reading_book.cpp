#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
int n;

int32_t main() {
    cin >> n;
    ll a[n];
    ll ts = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i], ts += a[i];
    sort(a, a + n);
    cout << max(2 * a[n - 1], ts) << "\n";
}
