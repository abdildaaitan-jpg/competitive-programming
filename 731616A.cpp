#include <bits/stdc++.h>

using ll = long long;
#define sz(v) ((int)v.size())
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
const ll maxn = 1e18 + 7;
const ll MOD = 1e9 + 7;
int gcd(int a, int b) {if (b == 0) return a; return gcd(b, a % b);}
int lcm(int a, int b) {return a / gcd(a, b) * b;}
int binpow(int a, int b) {
    int res = 1; 
    while (b > 0) { if (b & 1) res = (res * a) % MOD; a = (a * a) % MOD; b /= 2; }
    return res;
}
void up(int &x, int y) { x = max(x, y); return; }
void down(int &x, int y) { x = min(x, y); return; }

bool check(int n, int B, vector < pair < int, int >> t, int k, deque < int > N, deque < int > M) {
    for (int i = 0; i < N.size(); ) if (N[i] > n) N.ppf(); else break;
    for (int i = 0; i < M.size(); ) if (M[i] > n) M.ppf(); else break;
    
    for (int i = 1; i <= k; i++) {
        if (t[i].fi > n) {
            if (N.empty()) return false;
            int sub = t[i].fi - N[0];
            N.ppf();
            B -= sub;
        }
        if (t[i].se > n) {
            if (M.empty()) return false;
            int sub = t[i].se - M[0];
            M.ppf();
            B -= sub;
        }
    }
    return (B >= 0);
}

void solve() {
    int n, m, k, B;
    cin >> n >> m >> k >> B;
    
    int l = k, r = min(n, m);
    
    vector < pair < int, int >> t(k + 1);
    vector < bool > nn(n + 1, 0), mm(m + 1, 0);
    
    ll x = maxn, y = maxn; 
    for (int i = 1; i <= k; i++) {
        cin >> t[i].fi >> t[i].se;
        x = min((ll)t[i].fi, x);
        y = min((ll)t[i].se, y);
    }

    if (x > 1) {
        x--;
        for (int i = 1; i <= k; i++) t[i].fi -= x;
    }
    if (y > 1) {
        y--;
        for (int i = 1; i <= k; i++) t[i].se -= y;
    }
    
    for (int i = 1; i <= k; i++) {
        nn[t[i].fi] = 1;
        mm[t[i].se] = 1;
    }  
    
    deque < int > N, M;
    
    for (int i = 1; i <= n; i++) {
        if (!nn[i]) N.pb(i);
        if (!mm[i]) M.pb(i);
    }
    
    reverse(all(N)); reverse(all(M));
    
    while (l != r) {
        int mid = (l + r) / 2;
        if (check(mid, B, t, k, N, M)) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    
    if (check(l, B, t, k, N, M)) cout << l;
    else cout << -1;

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