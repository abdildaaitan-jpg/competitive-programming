#include <bits/stdc++.h>

using ll = long long;
#define sz(v) ((int)v.size())
#define se second
#define fi first
#define upb upper_bound
#define lwb lower_bound
#define pb push_back
#define eb emplace_back
#define int ll
#define pofik continue
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
// #define get(v,n) get<n>(v)
using namespace std;
const ll maxn = 1e18 + 7;
const ll MOD = 1e9 + 7;
const ll N = 10;
int gcd(int a, int b) {if (b == 0) return a; return gcd(b, a % b);}
int lcm(int a, int b) {return a / gcd(a, b) * b;}
int binpow(int a, int b) {
    int res = 1; 
    while (b > 0) { if (b & 1) res = (res * a) % MOD; a = (a * a) % MOD; b /= 2; }
    return res;
}
void up(int &x, int y) { x = max(x, y); return; }
void down(int &x, int y) { x = min(x, y); return; }

int n, m;
vector < vector < int >> g;
vector < bool > used;
deque < int > trip;
int st;

bool cycle = 0, reconst = 0;

void dfs(int v, int parent) {
    used[v] = 1;
    
    for (int to: g[v]) {
        if (cycle) pofik;
        if (!used[to]) {
            dfs(to, v);
        }
        else if (to != parent) {
            cycle = 1;
            reconst = 1;
            st = to;
            trip.pb(v);
            trip.pb(to);
            return;
        }
    }
    if (reconst) {
        trip.push_front(v);
        if (v == st) reconst = 0;
    }
}

void solve() {
    cin >> n >> m;
    g.resize(n + 1); used.resize(n + 1, 0);
    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }    
    for (int i = 1; i <= n; i++) {
        if (!cycle && !used[i]) {
            dfs(i, -1);
        }
    }
    if (!cycle) {
        cout << "IMPOSSIBLE";
    }
    else {
        cout << trip.size() << '\n';
        for (int it: trip) cout << it << ' ';
    }
    return;
}
signed main() {
    // freopen("cowdance.in", "r", stdin);
    // freopen("cowdance.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}