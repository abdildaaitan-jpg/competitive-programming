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

vector < int > t_max, t_min, v;

void build_min(int n, int s, int e) {
    if (s == e) {
        t_min[n] = v[s];
        return;
    }
    int mid = (s + e) / 2;
    build_min(n << 1, s, mid);
    build_min(n << 1 | 1, mid + 1, e);
    t_min[n] = min(t_min[n << 1], t_min[n << 1 | 1]);
}

void build_max(int n, int s, int e) {
    if (s == e) {
        t_max[n] = v[s];
        return;
    }
    int mid = (s + e) / 2;
    build_max(n << 1, s, mid);
    build_max(n << 1 | 1, mid + 1, e);
    t_max[n] = max(t_max[n << 1], t_max[n << 1 | 1]);
}

int get_min(int n, int s, int e, int l, int r) {
    if (s > r || e < l) return maxn;
    if (s >= l && e <= r) return t_min[n];
    int mid = (s + e) / 2;
    return min(get_min(n << 1, s, mid, l, r), get_min(n << 1 | 1, mid + 1, e, l, r));
}

int get_max(int n, int s, int e, int l, int r) {
    if (s > r || e < l) return -maxn;
    if (s >= l && e <= r) return t_max[n];
    int mid = (s + e) / 2;
    return max(get_max(n << 1, s, mid, l, r), get_max(n << 1 | 1, mid + 1, e, l, r));
}

void solve() {
    int n, k;
    cin >> n >> k;
    t_min.resize(n * 4); t_max.resize(n * 4); v.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    build_min(1, 1, n);
    build_max(1, 1, n);

    int l = 1, r = 1;
    int subarray = 0;
    while (r <= n) {
        if (get_max(1, 1, n, l, r) - get_min(1, 1, n, l, r) <= k) {
            subarray += r - l + 1;
            r++; 
        }
        else l++;
    }
    cout << subarray;
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