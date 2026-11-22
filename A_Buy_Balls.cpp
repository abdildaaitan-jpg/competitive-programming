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
#define pf pop_back
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

vector < int > pref, t;

void build(int n, int s, int e) {
    if (s == e) {
        t[n] = pref[s];
        return;
    }
    int mid = (s + e) / 2;
    build(n << 1, s, mid);
    build(n << 1 | 1, mid + 1, e);
    t[n] = max(t[n << 1], t[n << 1 | 1]);
}

int get(int n, int s, int e, int l, int r) {
    if (s > r || e < l) return -maxn;
    if (s >= l && e <= r) return t[n];
    int mid = (s + e) / 2;
    return max(get(n << 1, s, mid, l, r), get(n << 1 | 1, mid + 1, e, l, r));
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector < int > b(n + 1), w(m + 1);
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= m; i++) cin >> w[i];

    sort(b.begin() + 1, b.end());
    reverse(b.begin() + 1, b.end());
    sort(w.begin() + 1, w.end());
    reverse(w.begin() + 1, w.end());
    
    pref.resize(n + 1); t.resize(n * 4);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + b[i];
    }

    build(1, 1, n);

    ll sum = 0, ans = 0;

    for (int i = 0; i <= min(n, m); i++) {
        sum += w[i];
        ans = max(ans, get(1, 1, n, i, n) + sum);
    }

    cout << ans << '\n';
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