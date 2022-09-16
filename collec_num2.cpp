#include <bits/stdc++.h>
using namespace std;
int32_t main() {
    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    vector<int> u(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v[i]--;
        u[v[i]] = i;
    }

    int cnt = 1;
    for (int i = 1; i < n; i++)
        if (u[i] < u[i - 1]) cnt++;

    int f, s;
    for (int i = 0; i < m; i++) {
        cin >> f >> s;
        f--, s--;
        set<pair<int, int>> ss;
        int e1 = v[f];
        int e2 = v[s];
        if (e1 > e2) {
            swap(e1, e2);
            swap(f, s);
        }

        if (e1 - 1 >= 0) ss.insert({e1 - 1, e1});
        if (e2 + 1 < n) ss.insert({e2, e2 + 1});
        ss.insert({e1, e1 + 1});
        ss.insert({e2 - 1, e2});

        for (auto p : ss) {
            if (u[p.first] > u[p.second]) cnt--;
        }
        swap(u[e1], u[e2]);
        swap(v[f], v[s]);
        for (auto p : ss) {
            if (u[p.first] > u[p.second]) cnt++;
        }

        cout << cnt << endl;
    }
}
