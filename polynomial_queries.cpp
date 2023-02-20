#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

#define int long long
#define ff     first
#define ss     second
#define ar     array
#define sz(v)  ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define endl   '\n'
#define mp     make_pair

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
template <class T> void _print(array<T, 2> p) { cerr << "{"; _print(p[0]); cerr << ","; _print(p[1]); cerr << "}"; }
template <class T> void _print(set<T> s1) { cerr << "["; for (T i : s1) { _print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(vector<T> v1) { cerr << "["; for (T i : v1) { _print(i); cerr << " ";} cerr << "\b]"; }
template <class T, class V> void _print(map<T, V> m1) { cerr << "["; for (auto x : m1) { _print(x); cerr << " "; } cerr << "\b]"; }
// clang-format on

const int mxN = 2e5 + 7;

int n, m, x[mxN], ans[mxN];
int t[4 * mxN], lz1[4 * mxN], lz2[4 * mxN];

void push(int v) {
    lz1[v * 2] += lz1[v];
    lz1[v * 2 + 1] += lz1[v];
    lz2[v * 2] += lz2[v];
    lz2[v * 2 + 1] += lz2[v];

    /* t[v * 2] += lz1[v]; */
    /* t[v * 2 + 1] += lz1[v]; */

    lz2[v] = lz1[v] = 0;
}

void build(int v, int l = 0, int r = n - 1) {
    if (l == r)
        t[v] = x[l];
    else {
        int m = (l + r) / 2;
        build(v * 2, l, m);
        build(v * 2 + 1, m + 1, r);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

void upd(int v, int p, int q, int w, int l = 0, int r = n - 1) {
    if (p > q)
        return;
    if (l == p && r == q) {
        t[v] += lz1[v] + (w * lz2[v]);
    } else {
        push(v);
        int m = (l + r) / 2;
        int g = min(q, m) - p + 1;

        upd(v * 2, p, min(q, m), g, l, m);
        upd(v * 2 + 1, max(m + 1, p), q, g, m + 1, r);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

int qry(int v, int p, int q, int l = 0, int r = n - 1) {
    if (p > q) {
        return 0;
    }
    if (l == p && r == q) {
        return t[v];
    } else {
        int m = (l + r) / 2;
        int g = min(q, m) - p + 1;
        cerr << "\n";
        return qry(v * 2, p, min(q, m), l, m) +
               qry(v * 2 + 1, max(m + 1, p), q, m + 1, r);
    }
}

int32_t main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    build(1);
    while (m--) {
        int qt, a, b;
        cin >> qt >> a >> b, --a, --b;
        if (qt == 1) {
            int g = b - a + 1;
            int val = g * (g + 1) / 2;
            upd(1, a, b, val);
        } else {
            cout << qry(1, a, b) << "\n";
            cerr << "---\n";
        }
    }
}
