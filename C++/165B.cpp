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
const ll maxn = 1e18;
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
int n, k;
bool check(int v) {
    int sum = 0;
    for (int i = 0; i <= 30; i++) {
        if (sum >= n) break;
        int plus = v / pow(k, i);
        if (plus == 0) return 0;
        else sum += plus;
    }
    return true;
}
void solve() {
    cin >> n >> k;
    int l = 1, r = n;
    while (l != r) {
        int mid = (l + r) /2;
        if (check(mid)) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    cout << l;
    return;
}
signed main() {
    // freopen("cowdance.in", "r", stdin);
    // freopen("cowdance.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}
