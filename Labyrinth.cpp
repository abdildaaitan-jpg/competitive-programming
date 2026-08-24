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
vector < string > g;
vector < vector < bool >> used;
deque < char > path;
pair < int, int > A, B, C;
bool valPath = 0, reconst = 0;

void dfs(int u, int v) {
    used[u][v] = 1;
    if (u == B.fi && v == B.se) {
        valPath = 1;
        reconst = 1;
        C = B;
        return;
    }
    if (!reconst && u < n - 1 && (g[u + 1][v] == '.' || g[u + 1][v] == 'B') && !used[u + 1][v]) {
        dfs(u + 1, v);
    }
    if (!reconst && v < m - 1 && (g[u][v + 1] == '.' || g[u][v + 1] == 'B') && !used[u][v + 1]) {
        dfs(u, v + 1);
    }
    if (!reconst && u > 0 && (g[u - 1][v] == '.' || g[u - 1][v] == 'B') && !used[u - 1][v]) {
        dfs(u - 1, v);
    }
    if (!reconst && v > 0 && (g[u][v - 1] == '.' || g[u][v - 1] == 'B') && !used[u][v - 1]) {
        dfs(u, v - 1);
    }

    if (reconst) {
        if (u == C.fi + 1) {
            path.push_front('U');
        }
        else if (u == C.fi - 1) {
            path.push_front('D');
        }
        else if (v == C.se - 1) {
            path.push_front('R');
        }
        else if (v == C.se + 1) {
            path.push_front('L');
        }
        C.fi = u; C.se = v;
    }
}

void solve() {
    cin >> n >> m;
    g.resize(n); used.resize(n, vector < bool > (m, 0));
    for (auto &it: g) cin >> it;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'A') {
                A.fi = i; A.se = j;
            }
            else if (g[i][j] == 'B') {
                B.fi = i; B.se = j;
            }
        }
    }
    used[A.fi][A.se] = 1;
    dfs(A.fi, A.se);
    if (valPath) {
        cout << "YES\n" << path.size() << '\n';
        for (auto it: path) cout << it << ' ';
    }
    else {
        cout << "NO";
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