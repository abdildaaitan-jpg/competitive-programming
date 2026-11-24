#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
#define sz(v) ((int)v.size())
// #define int ll
#define se second
#define fi first
#define upb upper_bound
#define lwb lower_bound
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define pofik continue
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
// #define get(v,n) get<n>(v)
using namespace std;
const ll maxn = (ll) 1e18;
const ll MOD = 1e9 + 7;
const ld pi = acos(-1);
int gcd(int a, int b) {if (b == 0) return a; return gcd(b, a % b);}
int lcm(int a, int b) {return a / gcd(a, b) * b;}
int binpow(int a, int b) {
    int res = 1; 
    while (b > 0) { if (b & 1) res = (res * a) % MOD; a = (a * a) % MOD; b /= 2; }
    return res;
}
void up(int &x, int y) { x = max(x, y); return; }
void down(int &x, int y) { x = min(x, y); return; }

void solve() {
    int n;
    cin >> n;
    vector < vector < int >> t(n + 1, vector < int > (n + 1));
    vector < vector < int >> v(2 * n + 1, vector < int > (2 * n + 1, 0)), pref(v), prefD(v);
    map < int, pair < pair < int, int >, pair < int, int >>> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char x; cin >> x;
            t[i][j] = x - '0';
        }
    }

    for (int i = 1; i <= 2 * n; i++) {
        for (int j = 1; j <= 2 * n; j++) {
            if (i <= n && j <= n) v[i][j] = t[i][j];
            if (i > n || j > n) v[i][j] = t[(i % n == 0) ? n : i % n][(j % n == 0) ? n : j % n];

            pref[i][j] = ((i > 1) ? pref[i - 1][j] : 0) + 
                ((j > 1) ? pref[i][j - 1] : 0) -
                ((i > 1 && j > 1) ? pref[i - 1][j - 1] : 0) + 
                v[i][j];

            prefD[i][j] = ((i > 1 && j > 1) ? prefD[i - 1][j - 1] : 0) + v[i][j];
        }
    }

    for (int i = 1; i <= n + 1; i++) {
        for (int j = 1; j <= n + 1; j++) {
            int cur = prefD[i + n - 1][j + n - 1] - ((i > 1 && j > 1) ? prefD[i - 1][j - 1] : 0);
            
            int left = pref[i + n - 1][j + n - 1] -
            ((i > 1) ? pref[i - 1][j + n - 1] : 0) -
            ((j > 1) ? pref[i + n - 1][j - 1] : 0) + 
            ((i > 1 && j > 1) ? pref[i - 1][j - 1] : 0);
            m[left - cur + n - cur] = {{i, j}, {i + n - 1, j + n - 1}};
        }
    }

    for (auto [left, p]: m) {
        cout << left << '\n';
        // cout << p.fi.fi << ' ' << p.fi.se << '\n';
        // cout << p.se.fi << ' ' << p.se.se << '\n';
        break;
    }
    return;
}

signed main() {
    // freopen("cowdance.in", "r", stdin);
    // freopen("cowdance.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}