#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << " " << x << "\n"
#define ll long long
#define ar array

const ll mxN = 1e18, mxD = 18, mxX = 180;
ll l;
string r, l1;

ll dp[19][10][2][2];

ll dd(string &s, ll n, ll p, bool lz, bool tc) {
    if (n == 0) return 1;

    if (p != -1 && dp[n][p][lz][tc] != -1) return dp[n][p][lz][tc];

    int ub = tc ? (s[s.length() - n] - '0') : 9;
    ll ans = 0;
    for (int i = 0; i <= ub; i++) {
        if (i == p && lz == 0) continue;
        ans += dd(s, n - 1, i, lz & (i == 0), (tc & (i == ub)));
    }

    return dp[n][p][lz][tc] = ans;
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> l >> r;
    l--;
    l1 = to_string(l);

    ll ans = dd(r, r.size(), -1, 1, 1);
    memset(dp, -1, sizeof(dp));
    ll ans1 = dd(l1, l1.size(), -1, 1, 1);
    cout << ans - ans1;
}
