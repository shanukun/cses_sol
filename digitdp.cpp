#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << " " << x << "\n"
#define ll long long
#define ar array

const ll mxN = 1e18, mxD = 18, mxX = 180;
string l, r;
ll x;

int dp[mxD + 1][mxX][2];

ll dd(ll n, ll x, bool tc) {
    if (x < 0) return 0;
    if (n == 1) {
        if (x >= 0 && x <= 9) return 1;
        return 0;
    }

    if (dp[n][x][tc] != -1) return dp[n][x][tc];

    ll ans = 0;
    int ub = tc ? (r[r.length() - n] - '0') : 9;
    for (int i = 0; i <= ub; i++) {
        ans += dd(n - 1, x - i, (tc & (i == ub)));
    }

    return dp[n][x][tc] = ans;
}

int main() {
    cin >> l >> r;
    cin >> x;
    memset(dp, -1, sizeof(dp));
    cout << dd(r.size(), x, 1) << "\n";

    for (int i = 0; i <= (int)r.size(); i++) {
        for (int j = 0; j <= x; j++)
            cerr << dp[i][j][0] << " ";
        cerr << "\n";
    }
}
