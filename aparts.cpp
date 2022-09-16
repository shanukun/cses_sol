#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> apl(n), apa(m);
    for (int i = 0; i < n; i++)
        cin >> apl[i];
    for (int i = 0; i < m; i++)
        cin >> apa[i];
    sort(apl.begin(), apl.end());
    sort(apa.begin(), apa.end());
    int ans = 0;
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (apa[j] - k <= apl[i] && apa[j] + k >= apl[i]) {
            ans++;
            i++, j++;
        } else if (apa[j] - k > apl[i]) {
            i++;
        } else if (apa[j] + k < apl[i]) {
            j++;
        }
    }
    cout << ans << endl;
}
