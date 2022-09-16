#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define endl '\n'

// clang-format off
#ifdef PRATHCP
#define debug(x) cerr << #x << " : "; _print(x); cerr << endl;
#else
#define debug(x);
#endif

void _print(int a) { cerr << a; }
void _print(string a) { cerr << a; }

template <class T, class V> void _print(pair<T, V> p);
template <class T> void _print(set<T> s1);
template <class T> void _print(vector<T> v1);
template <class T, class V> void _print(map<T, V> m1);
template <class T, class V> void _print(pair<T, V> p) { cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}"; }
template <class T> void _print(set<T> s1) { cerr << "["; for (T i : s1) { _print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(vector<T> v1) { cerr << "["; for (T i : v1) { _print(i); cerr << " ";} cerr << "\b]"; }
template <class T, class V> void _print(map<T, V> m1) { cerr << "["; for (auto x : m1) { _print(x); cerr << " "; } cerr << "\b]"; }
// clang-format on
/* ------------------------------------------------------------------------- */

#define pii pair<int, int>

bool comp(pair<pii, int> a, pair<pii, int> b) {
    if (a.first.first == b.first.first) return a.first.second > b.first.second;
    return a.first.first < b.first.first;
}

int32_t main() {
#ifdef PRATHCP
    freopen("err", "w", stderr);
#endif
    int n;
    cin >> n;
    vector<pair<pii, int>> v;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({{a, b}, i});
    }
    sort(v.begin(), v.end(), comp);

    int fa = v[n - 1].first.second;
    vector<int> ans1(n, 0);
    for (int i = n - 2; i >= 0; i--) {
        if (v[i].first.second >= fa)
            ans1[v[i].second] = 1;
        else
            fa = v[i].first.second;
    }

    if (v[n - 1].first.second == v[n - 2].first.second &&
        v[n - 1].first.first == v[n - 2].first.first)
        ans1[n - 1] = 1;

    int mx = 0;
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++) {
        if (v[i].first.second <= mx)
            ans[v[i].second] = 1;
        else
            mx = v[i].first.second;
    }
    if (v[0].first.second == v[1].first.second &&
        v[0].first.first == v[1].first.first)
        ans[0] = 1;

    for (int i = 0; i < n; i++)
        cout << ans1[i] << " ";
    cout << endl;

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
}
