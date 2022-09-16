#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> nums(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        mp[nums[i]] = i + 1;
    }
    bool f = false;
    for (int i = 0; i < n && !f; i++) {
        if (mp.count(x - nums[i]) > 0 && i + 1 != mp[x - nums[i]]) {
            cout << i + 1 << " " << mp[x - nums[i]] << endl;
            f = true;
            break;
        }
    }
    if (!f) cout << "IMPOSSIBLE" << endl;
}
