#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    set<int> s;
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        s.insert(num);
    }
    int ans = s.size();
    cout << ans << endl;
}
