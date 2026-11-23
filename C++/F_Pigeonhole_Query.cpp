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

void solve() {
    int n, q;
    cin >> n >> q;
    vector < int > v(n + 1, 1);
    map < int, int > pos;

    for (int i = 1; i <= n; i++) pos[i] = i;
    
    int sum = 0;
    
    while (q--) {
        int x; cin >> x;
        
        if (x == 2) {
            cout << sum << '\n';
        }
        else {
            int p, h;
            cin >> p >> h;

            if (pos[p] == h) pofik;
            
            
            v[pos[p]]--;
            v[h]++;
            
            if (v[pos[p]] == 1) sum--;
            if (v[h] == 2) sum++;

            pos[p] = h;
            
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