#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    int x, n;
    cin >> x >> n;
    set<int> s;
    s.insert(0);
    s.insert(x);
    multiset<int> ms;
    ms.insert(x);

    for (int i = 0; i < n; i++) {
        int no;
        cin >> no;
        auto it = s.upper_bound(no);
        int e1 = *it;
        int e2 = *--it;

        auto ait = ms.find(e1 - e2);
        ms.erase(ait);
        ms.insert(e1 - no);
        ms.insert(no - e2);
        s.insert(no);
        auto lit = ms.end();
        cout << *--lit << " ";
    }
    cout << endl;
}
