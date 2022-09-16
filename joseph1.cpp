#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define o_set                                    \
    tree<int, null_type, less<int>, rb_tree_tag, \
         tree_order_statistics_node_update>

int32_t main() {
    int n, k;
    cin >> n >> k;
    o_set v;
    for (int i = 0; i < n; i++) {
        v.insert(i + 1);
    }

    int s = 0;
    while (!v.empty()) {
        s = (s + k) % v.size();
        auto it = v.find_by_order(s);
        cout << *it << " ";
        v.erase(it);
    }
    cout << endl;
}
