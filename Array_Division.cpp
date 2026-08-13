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
vector < int > nums;
bool check(int mx_l) {
    int cnt = 1, sum = 0;
    for (int it = 0; it < n; it++) {
        if (nums[it] > mx_l) return 0;
        sum += nums[it];    
        if (sum > mx_l) {
            cnt++;
            sum = nums[it];
        }
    }
    return cnt <= k;
}
void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int it;
        cin >> it;
        nums.pb(it);
    }
    int l = 0, r = 0;
    for (int it: nums) {
        r += it;
        up(l, it);
    }
    while (l != r) {
        int mid = l + (r - l) / 2;
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
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}
// 