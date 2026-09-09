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
vector < vector < int >> g, r_g;
vector < bool > used, usen;


void dfs(int v) {
    used[v] = 1;
    
    for (int to: g[v]) {
        if (!used[to]) {
            dfs(to);
        }
    }
}

void r_dfs(int v) {
    usen[v] = 1;

    for (int to: r_g[v]) {
        if (!usen[to]) {
            r_dfs(to);
        }
    }
}

void solve() {
    cin >> n >> m;
    g.resize(n + 1); r_g.resize(n + 1); used.resize(n + 1, 0); usen.resize(n + 1, 0);
    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        g[u].pb(v);
        r_g[v].pb(u);
    }    

    dfs(1);
    r_dfs(1);

    for (int i = 2; i <= n; i++) {
        if (!used[i]) {
            cout << "NO\n";
            cout << 1 << ' ' << i;
            return;
        }
    }
    
    for (int i = 2; i <= n; i++) {
        if (!usen[i]) {
            cout << "NO\n";
            cout << i << ' ' << 1;
            return;
        }
    }

    cout << "YES";
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