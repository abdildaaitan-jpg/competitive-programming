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

vector < int > vv, t;
int inv = 0;

void upd(int n, int s, int e, int i) {
    if (s == e) {
        t[n]++;
        return;
    }
    int mid = (s + e) / 2;
    if (i <= mid) upd(n << 1, s, mid, i);
    else upd(n << 1 | 1, mid + 1, e, i);
    t[n] = t[n << 1] + t[n << 1 | 1];
}

void get(int n, int s, int e, int l, int r) {
    if (s > r || e < l) return;
    if (s >= l && e <= r) {
        inv += t[n];
        return;
    }
    if (s == e) return;
    int mid = (s + e) / 2;
    get(n << 1, s, mid, l, r);
    get(n << 1 | 1, mid + 1, e, l, r);
}

void ell(int n, int s, int e, int i) {
    if (s == e) {
        t[n]--;
        return;
    }
    int mid = (s + e) / 2;
    if (i <= mid) ell(n << 1, s, mid, i);
    else ell(n << 1 | 1, mid + 1, e, i);
    t[n] = t[n << 1] + t[n << 1 | 1];
}

void next(int n, int s, int e, int l, int r) {
    if (s > r || e < l) return;
    if (s >= l && e <= r) {
        inv -= t[n];
        return;
    }
    if (s == e) return;
    int mid = (s + e) / 2;
    next(n << 1, s, mid, l, r);
    next(n << 1 | 1, mid + 1, e, l, r);
} 


void solve() {
    int n, k;
    cin >> n >> k;
    vv.resize(n); 
    for (int &it: vv) cin >> it;

    vector < int > vvv = vv;
    sort(all(vvv));
    vvv.erase(unique(all(vvv)), vvv.end());

    vector < int > v(1);

    for (int i = 0; i < vv.size(); i++) {
        v.pb(lwb(all(vvv), vv[i]) - vvv.begin() + 1);
    }

    int nn = vvv.size();
    t.resize(nn * 4);

    int l = 1, r = k;

    for (int i = 1; i <= k; i++) {
        get(1, 1, nn, v[i] + 1, nn);
        upd(1, 1, nn, v[i]);
    }
    
    cout << inv << ' ';
    r++;

    while (r <= n) {
        ell(1, 1, nn, v[l]);
        if (v[l] > 1) next(1, 1, nn, 1, v[l] - 1); 
        upd(1, 1, nn, v[r]);
        l++;
        get(1, 1, nn, v[r] + 1, nn);
        cout << inv << ' ';
        r++;
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