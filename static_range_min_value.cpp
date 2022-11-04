#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x << ":" << x << "\n";

#define ll long long
#define ar array

const int mxN = 2e5 + 7, L = 20;

int n, q, mt[mxN][L];

int main() {
    cin >> n >> q;
    for (int i = 0; i < n; ++i)
        cin >> mt[i][0];

    for (int i = 1; i < L; i++)
        for (int j = 0; j + (1 << i) - 1 < n; j++)
            mt[j][i] = min(mt[j][i - 1], mt[j + (1 << (i - 1))][i - 1]);

    while (q--) {
        int a, b;
        cin >> a >> b, --a, --b;
        int i = L;
        while (a + (1 << i) - 1 > b)
            --i;

        cout << min(mt[a][i], mt[b - (1 << i) + 1][i]) << "\n";
    }
}
