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
    int n, max_ans = 0;
    cin >> n;
    vector < int > pl(n);
    for (int &it: pl) cin >> it;
    map < int, int > cnt_pl;
    int l = 0;
    for (int r = 0; r < n; r++) {
        cnt_pl[pl[r]]++;
        while (cnt_pl[pl[r]] > 1) {
            cnt_pl[pl[l]]--;
            l++;
        }
        up(max_ans, r - l + 1);
    }
    cout << max_ans;
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
