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

bool check_inc(int a, int b) {
    return (a | b) != a;
}

void solve() {
    cin >> n;
    vector < int > orray(n), good_orray;
    vector < bool > used(n, 0);

    for (int &it: orray) cin >> it;

    sort(all(orray));
    reverse(all(orray));
    int m = 0;
    used[m] = 1;
    int cur = orray[m];
    good_orray.pb(cur);

    for (int i = 0; i < n; i++) {
        if (!used[i] && check_inc(cur, orray[i])) {
            used[i] = 1;
            cur = orray[i];
            good_orray.pb(cur);        
        }
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) good_orray.pb(orray[i]);
    }

    for (int it: good_orray) cout << it << ' ';
    cout << '\n';
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