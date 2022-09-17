#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxN = 2e5;
int n, a, b;
ll ps[mxN + 1];

int main() {
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++)
        cin >> ps[i], ps[i] += ps[i - 1];

    ll ans = -1e18;
    set<pair<ll, int>> s;
    for (int i = a; i <= b; i++)
        s.insert({ps[i], i});
    for (int i = 1; i + a - 1 <= n; i++) {
        ans = max(s.rbegin()->first - ps[i - 1], ans);
        s.erase({ps[i + a - 1], i + a - 1});
        if (i + b <= n) s.insert({ps[i + b], i + b});
    }
    cout << ans << "\n";
}
