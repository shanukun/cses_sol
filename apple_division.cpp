#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> sb;
void ss(vector<int> &v, int i, ll s) {
    if (i == (int)v.size()) {
        sb.push_back(s);
        return;
    }
    ss(v, i + 1, s);
    ss(v, i + 1, v[i] + s);
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    ll ts = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        ts += v[i];
    }
    ss(v, 0, 0);
    ll mn = 2e11;
    for (int i = 0; i < (int)sb.size(); i++) {
        mn = min(mn, abs(sb[i] - (ts - sb[i])));
    }
    cout << mn << "\n";
}
