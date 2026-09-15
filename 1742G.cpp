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
 
int n;

int get_inc(int a, int b) {
    int inc = (a | b);
    return inc;
}

void solve() {
    cin >> n;
    vector < int > orray(n), good_orray;
    vector < bool > used(n, 0);

    for (int &it: orray) cin >> it;
    int cur = 0;
    
    for (int step = 0; step < min(n, (int)30); step++) {
        pair < int, int > max_inc = {cur, -1};
        for (int j = 0; j < n; j++) {    
            if (!used[j]) {
                int cur_inc = get_inc(cur, orray[j]);
                if (cur_inc > max_inc.fi) {
                    max_inc.fi = cur_inc; 
                    max_inc.se = j;
                }
            }
        }
        if (max_inc.se == -1) break;
        used[max_inc.se] = 1;
        cur = max_inc.fi;
        good_orray.pb(orray[max_inc.se]);  
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) good_orray.pb(orray[i]);
    }

    for (int it: good_orray) cout << it << ' ';
    cout << '\n';
    return;
}
 
signed main() {
    // freopen("cowdance.in", "r", stdin);
    // freopen("cowdance.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}