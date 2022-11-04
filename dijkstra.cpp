#include <bits/stdc++.h>

using namespace std;

#define ll     long long
#define ff     first
#define ss     second
#define ar     array
#define sz(v)  ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define endl   '\n'
#define pli    pair<long long, int>

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
/* ------------------------------------------------------------------------- */

const int mxN = 1e5 + 7;

int n, m;
ll d[mxN];
vector<pli> g[mxN];
bool vis[mxN];

void dijkstra(int src) {
    memset(d, -1, sizeof(d));
    set<pli> pq;
    pq.insert({0, src});
    d[src] = 0;

    while (pq.size()) {
        debug(pq);
        pli nf = *pq.begin();
        pq.erase(pq.begin());

        if (vis[nf.ss]) continue;
        vis[nf.ss] = true;

        for (pli c : g[nf.ss]) {
            if (d[nf.ss] + c.ss < d[c.ff] || d[c.ff] == -1) {
                d[c.ff] = d[nf.ss] + c.ss;
                pq.insert({d[c.ff], c.ff});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }
    dijkstra(1);
    for (int i = 1; i <= n; i++)
        cout << d[i] << " ";
}
