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
int n, c;
bool check(const vector < int > kora, int diss) {
    int cnt = 1, last_pos = kora[0];
    for (size_t i = 1; i < n; i++) {
        if (kora[i] - last_pos >= diss) {
            cnt++;
            last_pos = kora[i];
            if (cnt == c) {
                return 1;
            }
        }   
    }
    return 0;
}
void solve() {
    cin >> n >> c;
    vector < int > kora(n);
    for (int &it: kora) cin >> it;
    sort(all(kora));
    int l = 1, r = kora[n - 1] - kora[0];
    while (l != r) {
        int mid = l + (r - l + 1) / 2;
        if (check(kora, mid)) {
            l = mid;
        }
        else {
            r = mid - 1;
        }
    }
    cout << l << '\n';
    return;
}
signed main() {
    // freopen("cowdance.in", "r", stdin);
    // freopen("cowdance.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}