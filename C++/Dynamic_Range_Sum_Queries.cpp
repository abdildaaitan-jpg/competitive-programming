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

vector < int > t, v;

void build(int n, int s, int e) {
    if (s == e) {
        t[n] = v[s];
        return;
    }
    int mid = (s + e) / 2;
    build(n << 1, s, mid);
    build(n << 1 | 1, mid + 1, e);
    t[n] = t[n << 1] + t[n << 1 | 1];
}

void upd(int n, int s, int e, int i, int v) {
    if (s == e) {
        t[n] = v;
        return;
    }
    int mid = (s + e) / 2;
    if (i <= mid) upd(n << 1, s, mid, i, v);
    else upd(n << 1 | 1, mid + 1, e, i, v);
    t[n] = t[n << 1] + t[n << 1 | 1];
}

int get(int n, int s, int e, int l, int r) {
    if (r < s || l > e) return 0;
    if (l <= s && r >= e) return t[n];
    int mid = (s + e) / 2;
    return get(n << 1, s, mid, l, r) + get(n << 1 | 1, mid + 1, e, l, r);
}

void solve() {
    int n, m;
    cin >> n >> m;
    t.resize(n * 4); v.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    build(1, 1, n);
    int i, l, r;
    while (m--) {
        cin >> i >> l >> r;
        if (i == 1) {
            upd(1, 1, n, l, r);
        }
        else {
            cout << get(1, 1, n, l, r) << '\n';
        }
    }
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