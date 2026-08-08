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
const int maxn = 1e9 + 7;
const int MOD = 1e9 + 7;
const int N = 10;
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
    int n, ans = 0;
    cin >> n;
    map < int, int > cnt;
    vector < int > w(n), pr;
    pr.resize(n);
    for (int &it: w) cin >> it;
    partial_sum(all(w), pr.begin());
    for (int &it: pr) it = (it % n + n) % n;
    cnt[0] = 1;
    for (int it: pr) {
        ans += cnt[it];
        cnt[it]++;
    }
    cout << ans;
}
signed main() {
    // freopen("rvq.in", "r", stdin);
    // freopen("rvq.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) 
        solve();
    return 0;
}