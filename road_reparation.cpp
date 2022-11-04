#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

const int mxN = 1e5 + 1;

int n, m, pr[mxN], siz[mxN];
vector<ar<int, 3>> ed;

void make(int v) {
    pr[v] = v;
    siz[v] = 1;
}

int find(int v) {
    return v ^ pr[v] ? pr[v] = find(pr[v]) : v;
}

void union_s(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (siz[a] < siz[b]) swap(a, b);
        pr[b] = a;
        siz[a] += siz[b];
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        make(i);

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        ed.push_back({c, a, b});
    }
    sort(ed.begin(), ed.end());

    ll a1 = 0;
    int a2 = 0;
    for (int i = 0; i < m; ++i) {
        if (find(ed[i][1]) != find(ed[i][2])) {
            a1 += ed[i][0];
            union_s(ed[i][1], ed[i][2]);
            a2++;
        }
    }
    if (a2 < n - 1)
        cout << "IMPOSSIBLE";
    else
        cout << a1;
}
