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

void solve() {
    int n, q;
    cin >> n >> q;
    
    vector < int > t(n + 1);
    for (int i = 1; i <= n; i++) cin >> t[i];
    
    vector < int > R(n + 1, 0), L(n + 1, 0);
    
    R[n] = t[n];
    for (int i = n - 1; i >= 1; i--) {
        if (t[i] == 0) {
            R[i] == 0;
        } 
        else {
            R[i] = t[i] + R[i + 1];
        }
    }
    
    L[1] = t[1];
    for (int i = 2; i <= n; i++) {
        if (t[i] == 0) {
            L[i] = 0;
        }
        else {
            L[i] = t[i] + L[i - 1];
        }
    }
    
    
    int l, r;
    while (q--) {
        cin >> l >> r;
        r += ((r < n) ? R[r + 1] : 0);
        l -= ((l > 1) ? L[l - 1] : 0);
        cout << l << ' ' << r << '\n';
    }
    
    return;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) 
        solve();
    return 0;
}