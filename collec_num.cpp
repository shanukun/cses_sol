#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end());
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        if (v[i].second < v[i - 1].second) cnt++;
    }
    cout << cnt + 1 << endl;
}
