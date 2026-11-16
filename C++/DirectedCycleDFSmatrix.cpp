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

int n;
vector < vector < bool >> g;
vector < int > color;
bool cycle = 0;

void dfs(int v) {
    color[v] = 1;
    for (int to = 1; to <= n; to++) {
        if (g[v][to]) {
            if (color[to] == 0) {
                dfs(to);
            }
            else if (color[to] == 1) {
                cycle = 1;
            }
        }
    }
    color[v] = 2;
}

void solve() {
    cin >> n;
    g.resize(n + 1, vector < bool > (n + 1)); color.resize(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int tt; cin >> tt;
            g[i][j] = tt;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            dfs(i);
        }
    }    
    cout << ((cycle) ? "yes" : "no");
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