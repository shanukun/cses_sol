#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

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
const int mxN = 2e5;
int n, k;

int32_t main() {
    cin >> n >> k;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].second >> v[i].first;
    }
    sort(v.begin(), v.end());
    debug(v);

    int ans = 0;
    set<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        debug(s);
        if (sz(s) == 0) {
            s.insert(v[i]);
            ans++;
            continue;
        }
        auto it = s.lower_bound({v[i].second, 0});
        if (it != s.end() && it->first <= v[i].second) {
            s.erase(it);
            s.insert(v[i]);
            ans++;
        } else if (it != s.begin()) {
            it--;
            s.erase(it);
            s.insert(v[i]);
            ans++;
        } else if (sz(s) < k) {
            s.insert(v[i]);
            ans++;
        }
    }
    debug(s);
    cout << ans << "\n";
}
