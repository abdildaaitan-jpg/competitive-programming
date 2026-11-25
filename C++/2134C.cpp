#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
#define sz(v) ((int)v.size())
#define int ll
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
    vector < int > a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    int sum = 0;
    for (int i = 2; i <= n; i += 2) {
        if (i < n) {
            int cur = a[i - 1] + a[i + 1], cur_sum = 0;
            
            if (cur > a[i]) {
                cur_sum += cur - a[i];
                if (a[i + 1] >= cur_sum) {
                    a[i + 1] -= cur_sum;
                }
                else {
                    a[i + 1] = 0;
                }
            }

            sum += cur_sum;
        }
        else {
            if (a[i] < a[i - 1]) {
                sum += a[i - 1] - a[i];
            }
        }
    }
    cout << sum << '\n';

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