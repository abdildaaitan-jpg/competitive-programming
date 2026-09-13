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
bool valdiv = 0;
void dif(int a, int b) {
    if (a == m || b == m) valdiv = 1;
    if (valdiv) return;
    
    if (a % 3 == 0) {
        dif(a / 3, (a / 3) * 2);
    }
    if (b % 3 == 0) {
        dif(b / 3, (b / 3) * 2);
    }
}

void solve() {
    cin >> n >> m;
    valdiv = ((n == m) ? 1 : 0);
    if (n % 3 == 0) {
        dif(n / 3, (n / 3) * 2);
    }
    cout << ((valdiv) ? "YES" : "NO") << '\n';
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