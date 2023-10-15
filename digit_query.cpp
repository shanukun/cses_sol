#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    int q;
    ll k;
    cin >> q;
    while (q--) {
        cin >> k;
        if (k <= 9) {
            cout << k << "\n";
            continue;
        }

        ll n = 9;
        int i;
        for (i = 1; i <= 18; ++i) {
            if (n * i <= k) {
                k -= n * i;
                n *= 10;
            } else
                break;
        }
        ll a = k / i;
        a += 9 * pow(10, i - 2) * (i - 1);
        ll b = k % i;

        cout << "- " << b << "\n";
        if (b > 0) a++;
        vector<ll> v;
        while (a > 0)
            v.push_back(a % 10), a /= 10;
        if (b > 0) reverse(v.begin(), v.end());
        for (ll c : v)
            cout << c;
        cout << "\n";
        cout << v[b] << "\n";
    }
}
