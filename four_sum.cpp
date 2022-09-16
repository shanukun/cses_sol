#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second

int32_t main() {
    int n, x;
    cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    map<int, pair<int, int>> mp;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int ts = a[i] + a[j];
            auto it = mp.find(x - ts);
            if (it != mp.end()) {
                cout << 1 + it->second.first << " ";
                cout << 1 + it->second.second << " ";
                cout << 1 + i << " ";
                cout << 1 + j << "\n";
                return 0;
            }
        }
        for (int k = 0; k < i; ++k) {
            mp[a[k] + a[i]] = {k, i};
        }
    }
    cout << "IMPOSSIBLE";
}
