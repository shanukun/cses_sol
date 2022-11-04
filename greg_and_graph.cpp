#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ff first
#define ss second
#define ar array

const int mxN = 500;

ll n, rm[mxN], ans[mxN];
ll g[mxN][mxN];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];

    for (int k = 0; k < n; ++k)
        cin >> rm[k];
    reverse(rm, rm + n);

    for (int k = 0; k < n; ++k) {
        rm[k] -= 1;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                g[i][j] = min(g[i][j], g[i][rm[k]] + g[rm[k]][j]);

        for (int i = 0; i <= k; ++i) {
            for (int j = 0; j <= k; ++j) {
                ans[k] += g[rm[i]][rm[j]];
            }
        }
    }
    reverse(ans, ans + n);
    for (int i = 0; i < n; ++i)
        cout << ans[i] << " ";
}
