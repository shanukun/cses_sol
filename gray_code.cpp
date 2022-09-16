#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> v1;
    v1.push_back("0");
    v1.push_back("1");
    for (int i = 1; i < n; i++) {
        vector<string> v2;
        for (int j = 0; j < (int)v1.size(); j++) {
            v2.push_back("0" + v1[j]);
        }

        for (int j = v1.size() - 1; j >= 0; j--) {
            v2.push_back("1" + v1[j]);
        }

        v1 = v2;
        v2.clear();
    }
    for (string s : v1)
        cout << s << "\n";
}
