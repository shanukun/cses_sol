#include <bits/stdc++.h>
using namespace std;

stack<int> sort_stack(stack<int> &st) {
    if (st.size() == 1) return st;
    int te = st.top();
    st.pop();
    st = sort_stack(st);
    if (st.top() < te) {
        int ee = st.top();
        st.pop();
        st.push(te);
        st = sort_stack(st);
        st.push(ee);
    } else {
        st.push(te);
    }
    return st;
}

int main() {
    int n;
    cin >> n;
    stack<int> st;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        st.push(a);
    }
    st = sort_stack(st);
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}
