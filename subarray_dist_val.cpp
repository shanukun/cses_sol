#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(x) ((int)(x).size())

const int mxN = 2e5;
int a[mxN];
int n, k;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    map<int, int> s;
    ll cnt = 0;
    for (int i = 0, j = 0; i < n; i++) {
        while (j < n && (sz(s) < k || s.count(a[j]) > 0))
            s[a[j]]++, j++;
        cnt += j - i;
        s[a[i]]--;
        if (s[a[i]] == 0) s.erase(a[i]);
    }
    cout << cnt << "\n";
}
