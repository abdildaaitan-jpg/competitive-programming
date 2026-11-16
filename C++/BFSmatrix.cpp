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
vector < bool > used;
vector < int > dist;
queue < int > q;

void bfs(int start) {
    used[start] = 1;
    dist[start] = 0;
    q.push(start);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << ' ';
        for (int to = 1; to <= n; to++) {
            if (g[v][to] && !used[to]) {
                used[to] = 1;
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }
}

void solve() {
    cin >> n;
    g.resize(n + 1, vector < bool > (n + 1)); used.resize(n + 1, 0); dist.resize(n + 1);
    int it;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
           cin >> it; 
           g[i][j] = it; 
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            bfs(i);
        }
    }
    cout << '\n';
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << ' ';
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