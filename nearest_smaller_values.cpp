#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long

// can be solved using monotonic stack
int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int v[n] = {-1};
    v[0] = -1;
    stack<ar<int, 2>> s;
    s.push({a[0], 0});

    for (int i = 1; i < n; ++i) {
        while (!s.empty() && s.top()[0] >= a[i])
            s.pop();
        if (s.empty()) {
            v[i] = -1;
        } else {
            v[i] = s.top()[1];
        }
        s.push({a[i], i});
    }
    for (int i = 0; i < n; i++)
        cout << v[i] + 1 << " ";
    cout << "\n";
}

/* for (int i = 1; i < n; i++) { */
/*     // taking care of = here */
/*     if (a[i] > a[i - 1]) { */
/*         v[i] = i - 1; */
/*     } else { */
/*         int j = i - 1; */
/*         while (true) { */
/*             if (a[v[j]] >= a[i] && v[j] != -1) { */
/*                 j = v[j]; */
/*             } else */
/*                 break; */
/*         } */
/*         if (v[j] != -1) { */
/*             // loops end early and does no updates j */
/*             j = v[j]; */
/*             v[i] = j; */
/*         } else */
/*             v[i] = -1; */
/*     } */
/* } */
