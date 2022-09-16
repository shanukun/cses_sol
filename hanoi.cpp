#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;
void hanoi(int n, int s, int d, int h) {
    if (n == 1) {
        /* cout << s << " " << d << "\n"; */
        v.push_back({s, d});
    } else {
        hanoi(n - 1, s, h, d);
        hanoi(1, s, d, h);
        hanoi(n - 1, h, d, s);
    }
}

int main() {
    int n;
    cin >> n;
    hanoi(n, 1, 3, 2);
    cout << v.size() << "\n";
    for (auto p : v) {
        cout << p.first << " " << p.second << "\n";
    }
}

