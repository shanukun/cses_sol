#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, no;
    cin >> n;
    map<int, int> s;
    int cnt = 0, mx = 1;
    int lp = 0;
    for (int i = 0; i < n; i++) {
        cin >> no;
        if (s.count(no) > 0 && s[no] >= lp) {
            cnt = i - s[no];
            lp = s[no] + 1;
        } else {
            cnt++;
        }
        s[no] = i;
        mx = max(cnt, mx);
    }
    cout << mx << endl;
}
