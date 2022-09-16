#include <bits/stdc++.h>

using namespace std;

set<string> cs(string s) {
    set<string> st;
    if (s.size() == 1) {
        st.insert(s);
        return st;
    }
    st.insert(s);
    char c = s[s.size() - 1];
    s.pop_back();
    set<string> rs = cs(s);
    for (string a : rs) {
        string b = "";
        b.push_back(c);
        for (int i = 0; i <= (int)a.size(); i++) {
            string temp = a;
            st.insert(temp.insert(i, b));
        }
    }
    return st;
}

int main() {
    string s;
    cin >> s;
    set<string> st = cs(s);
    cout << st.size() << "\n";
    for (string a : st) {
        cout << a << "\n";
    }
}
