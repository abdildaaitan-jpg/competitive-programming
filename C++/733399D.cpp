#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
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
const ll maxn = 1e5 + 7;
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
    int n;
    cin >> n;
    deque < int > v(n + 1), zero, neg, two;
    map < int, pair < int, int >, greater < int >> t; 
    
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        if (v[i] == 0) zero.pb(i);
        if (v[i] < 0) neg.pb(i);
        if (v[i] == 2 || v[i] == -2) two.pb(i);
    }
    if (two.empty()) {
        cout << "0 " << n << '\n';
        return;
    }

    int nn = neg.size();
    if (zero.empty()) {
        if (neg.size() & 1) {
            int two_from_first = upb(all(two), n) - lwb(all(two), neg[0] + 1), 
                two_from_last = upb(all(two), neg[nn - 1] - 1) - lwb(all(two), 1);
            
            if (two_from_first >= two_from_last) {
                t[two_from_first] = {neg[0] + 1, n};
            } 
            else {
                t[two_from_last] = {1, neg[nn - 1] - 1};
            }
        }
        else {
            cout << 0 << ' ' << 0 << '\n';
            return;
        }
    }
    else {
        int last_idx = 1;
        zero.pb(n + 1);

        for (int i = 0; i < zero.size(); i++) {

            pair < int, int > part = {last_idx, zero[i] - 1};

            int count_neg = upb(all(neg), part.se) - lwb(all(neg), part.fi);

            if (count_neg & 1) {

                int first_neg = *lwb(all(neg), part.fi),
                    last_neg = *(upb(all(neg), part.se) - 1);  

                int two_from_first = upb(all(two), part.se) - lwb(all(two), first_neg + 1), 
                    two_from_last = upb(all(two), last_neg - 1) - lwb(all(two), part.fi);
                
                if (two_from_first >= two_from_last) {
                    t[two_from_first] = {first_neg + 1, part.se};
                } 
                else {
                    t[two_from_last] = {part.fi, last_neg - 1};
                }
            }
            else {
                int count_two = upb(all(two), part.se) - lwb(all(two), part.fi);
                t[count_two] = part;
            }

            last_idx = zero[i] + 1; 
        }
    }

    for (auto [u, v]: t) {
        cout << ((v.fi > 0) ? v.fi - 1 : v.fi) << ' ' << n - v.se << '\n';
        return;
    }

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