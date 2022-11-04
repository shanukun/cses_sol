#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

const int mxN = 1e5 + 1;

int n, m, cur_mx = -1, pr[mxN], siz[mxN];
unordered_set<int> st;

void make(int v) {
    pr[v] = v;
    siz[v] = 1;
}

int find(int v) {
    if (v == pr[v]) return v;
    return pr[v] = find(pr[v]);
}

void union_s(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (siz[a] < siz[b]) swap(a, b);
        pr[b] = a;
        siz[a] += siz[b];
        cur_mx = max(siz[a], cur_mx);
        st.erase(b);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        make(i);
        st.insert(i);
    }

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;

        union_s(a, b);

        cout << st.size() << " " << cur_mx << "\n";
    }
}
