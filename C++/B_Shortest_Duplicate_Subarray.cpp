#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
#define sz(v) ((int)v.size())
#define se second
#define fi first
#define upb upper_bound
#define lwb lower_bound
#define pb push_back
#define pf pop_back
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define pofik continue
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
// #define get(v,n) get<n>(v)
using namespace std;
const ll maxn = 2e6;
const ll MOD = 1e9 + 7;
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
    vector < int > v(n + 1);
    map < int, int > cnt;
    map < int, vector < int >> idx;

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        cnt[v[i]]++;
        idx[v[i]].pb(i);
    }

    int ans = maxn;
    bool var = 0;

    for (auto [x, i]: cnt) {
        if (i < 2) pofik;
        for (int l = 1; l < idx[x].size(); l++) {
            ans = min(ans, idx[x][l] - idx[x][l - 1] + 1);
            var = 1;
        }
    }

    if (var) cout << ans;
    else cout << -1;
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