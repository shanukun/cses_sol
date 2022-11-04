#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x << ":" << x << "\n";

#define ll long long
#define ar array

const int mxN = 2e5 + 7;

int n, q;
ll ps[mxN], x[mxN];

int main() {
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        ps[i + 1] = ps[i] + x[i];
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << ps[b] - ps[a - 1] << "\n";
    }
}
