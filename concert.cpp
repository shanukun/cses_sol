#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

/* #define int long long */
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

void solve() {
    int n, m;
    cin >> n >> m;

    set<int> s;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        s.insert(t);
        mp[t]++;
    }

    int num;
    for (int i = 0; i < m; i++) {
        cin >> num;
        auto it = s.upper_bound(num);
        if (it != s.begin()) it--;

        if (*it <= num && s.size() > 0) {
            cout << *it << endl;
            if (--mp[*it] <= 0) s.erase(*it);
        } else {
            cout << -1 << endl;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifdef PRATHCP
    freopen("err", "w", stderr);
#endif
    auto start1 = high_resolution_clock::now();
    solve();
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
#ifdef PRATHCP
    cerr << "Time: " << duration.count() / 1000 << endl;
#endif
}
