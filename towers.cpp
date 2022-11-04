#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, no;
    cin >> n;

    multiset<int> s;
    s.insert(INT_MAX);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> no;

        auto it = s.lower_bound(no);

        if (it == s.end() || *it == INT_MAX) {
            cnt++;
            s.insert(no);
        } else {
            s.erase(it);
            s.insert(no);
        }
    }
    cout << cnt << endl;
}
