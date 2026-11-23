#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
#define sz(v) ((int)v.size())
// #define int ll
#define se second
#define fi first
#define upb upper_bound
#define lwb lower_bound
#define pb push_back
#define pf push_front
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
    int n, m;
    cin >> n >> m;

    deque < deque < int >> v(n, deque < int > (m, 0));

    pair < int, int > fb, lb;
    bool fb_v = 0;
    int min_i = n, min_j = m, max_i = -1, max_j = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char x; cin >> x;
            if (x == '#') v[i][j] = 1;
            else if (x == '.') v[i][j] = -1;
            else v[i][j] = 0; 

            
            if (v[i][j] == 1) {
                down(min_i, i);
                down(min_j, j);
                up(max_i, i);
                up(max_j, j);
            }
            
        }
    }
    
    
    deque < deque < int >> pref(v.size(), deque < int > (v[0].size()));
    
    max_j = m - max_j - 1;
    max_i = n - max_i - 1;
    
    // cout << min_i << ' ' << min_j << '\n' << max_i << ' ' << max_j;
    while (min_j--) {
        for (int i = 0; i < (int)v.size(); i++) v[i].ppf();
    }
    while (min_i--) {
        v.ppf();
    }
    while (max_j--) {
        for (int i = 0; i < (int)v.size(); i++) v[i].ppb();    
    }
    while (max_i--) {
        v.ppb();
    }


    for (int i = 0; i < (int)v.size(); i++) {
        for (int j = 0; j < (int)v[0].size(); j++) {

            if (v[i][j] == -1) {
                cout << "No"; return;
            }

            // if (v[i][j] == 0) v[i][j] = 1;
            
            // if (!fb_v && v[i][j] == 1) { fb = {i, j}; fb_v = 1; }
            // if (v[i][j] == 1) lb = {i, j}; 
            
            // pref[i][j] = ((i > 0) ? pref[i - 1][j] : 0) + 
            //     ((j > 0) ? pref[i][j - 1] : 0) - 
            //     ((i > 0 && j > 0) ? pref[i - 1][j - 1] : 0) + 
            //     v[i][j];
            
            // cout << v[i][j] << ' ';
        }
        // cout << '\n';
    } 
    cout << "Yes";
    // int nn = lb.fi - fb.fi + 1, mm = lb.se - fb.se + 1;
    // int i = lb.fi, j = lb.se;
    // int sum = pref[i][j] - 
    //     ((i - nn >= 0) ? pref[i - nn][j] : 0) - 
    //     ((j - mm >= 0) ? pref[i][j - mm] : 0) + 
    //     ((j - mm >= 0 && i - nn >= 0) ? pref[i - nn][j - mm] : 0); 

    // cout << sum << ' ' << i << ' ' << j << ' ';
    // if (sum == nn * mm) cout << "Yes";
    // else cout << "No";
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