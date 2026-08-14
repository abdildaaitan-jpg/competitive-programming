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
int n; 
vector < pair < int, int >> balloon;

bool check(int num) {
    vector < int > balloon_queue;
    for (auto it: balloon) {
        balloon_queue.pb((num - it.fi) / it.se);
    }
    sort(all(balloon_queue));
    for (int i = 0; i < n; i++) {
        if (balloon_queue[i] < i) return 0;
    }
    return 1;
}
void solve() {
    cin >> n;
    int l = 0, r = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        balloon.eb(a, b);
        up(l, a);
        up(r, a + b * n);
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
    cout << l << '\n';
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