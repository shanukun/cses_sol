#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mxN = 2e5;
int n, x;

ar<ll, 2> a[mxN];

int main() {
    cin >> n >> x;

    for (int i = 0; i < n; ++i)
        cin >> a[i][0], a[i][1] = i + 1;

    sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        int k = n - 1;
        for (int j = i + 1; j < n; ++j) {
            while (a[i][0] + a[j][0] + a[k][0] > x)
                --k;
            if (a[i][0] + a[j][0] + a[k][0] == x && j < k) {
                cout << a[i][1] << " " << a[j][1] << " " << a[k][1] << "\n";
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}
