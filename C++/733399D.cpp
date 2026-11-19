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
    deque < int > v(n + 1), zero, neg, two, neg_one, neg_two;

    map < int, pair < int, int >, greater < int >> t; 
    
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        if (v[i] == 0) zero.pb(i);
        if (v[i] < 0) neg.pb(i);
        if (v[i] == -1) neg_one.pb(i);
        if (v[i] == 2 || v[i] == -2) two.pb(i);
        if (v[i] == -2) neg_two.pb(i); 
    }

    if (two.empty()) {
        cout << "0 " << n << '\n';
        return;
    }

    if (zero.empty()) {
        if (neg.size() & 1) {
            
            for (int i = 0; i < neg_one.size(); i++) {
                pair < int, int > left_side = ((neg_one[i] > 1) ? make_pair(1, neg_one[i] - 1) : make_pair(0, 0)),
                    right_side = ((neg_one[i] < n) ? make_pair(neg_one[i] + 1, n) : make_pair(0, 0));
                
                int two_in_left = upb(all(two), left_side.se) - lwb(all(two), left_side.fi), 
                    two_in_right = upb(all(two), right_side.se) - lwb(all(two), right_side.fi);  
                
                int neg_in_left = upb(all(neg), left_side.se) - lwb(all(neg), left_side.fi), 
                    neg_in_right = upb(all(neg), right_side.se) - lwb(all(neg), right_side.fi);

                if (two_in_left >= two_in_right && !(neg_in_left & 1)) {
                    t[two_in_left] = left_side;
                }
                else if (two_in_left < two_in_right && !(neg_in_right & 1)) {
                    t[two_in_right] = right_side;
                }
            }

            for (int i = 0; i < neg_two.size(); i++) {
                pair < int, int > left_side = ((neg_two[i] > 1) ? make_pair(1, neg_two[i] - 1) : make_pair(0, 0)), 
                    right_side = ((neg_two[i] < n) ? make_pair(neg_two[i] + 1, n) : make_pair(0, 0));
                    
                int two_in_left = upb(all(two), left_side.se) - lwb(all(two), left_side.fi),
                    two_in_right = upb(all(two), right_side.se) - lwb(all(two), right_side.fi); 

                int neg_in_left = upb(all(neg), left_side.se) - lwb(all(neg), left_side.fi), 
                    neg_in_right = upb(all(neg), right_side.se) - lwb(all(neg), right_side.fi);

                if (two_in_left >= two_in_right && !(neg_in_left & 1)) {
                    t[two_in_left] = left_side;
                }
                else if (two_in_left < two_in_right && !(neg_in_right & 1)) {
                    t[two_in_right] = right_side;
                }
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
                for (int j = 0; j < neg_two.size(); j++) {
                    if (part.fi > neg_two[j] || part.se < neg_two[j]) pofik;
                    pair < int, int > left_side = ((neg_two[j] > part.fi) ? make_pair(part.fi, neg_two[j] - 1) : make_pair(0, 0)), 
                    right_side = ((neg_two[j] < part.se) ? make_pair(neg_two[j] + 1, part.se) : make_pair(0, 0));
                    
                    int two_in_left = upb(all(two), left_side.se) - lwb(all(two), left_side.fi),
                        two_in_right = upb(all(two), right_side.se) - lwb(all(two), right_side.fi);

                    int neg_in_left = upb(all(neg), left_side.se) - lwb(all(neg), left_side.fi), 
                        neg_in_right = upb(all(neg), right_side.se) - lwb(all(neg), right_side.fi);

                    if (two_in_left >= two_in_right && !(neg_in_left & 1)) {
                        t[two_in_left] = left_side;
                    }
                    else if (two_in_left < two_in_right && !(neg_in_right & 1)) {
                        t[two_in_right] = right_side;
                    }
                }

                for (int j = 0; j < neg_one.size(); j++) {
                    if (part.fi > neg_one[j] || part.se < neg_one[j]) pofik;
                    pair < int, int > left_side = ((neg_one[j] > part.fi) ? make_pair(part.fi, neg_one[j] - 1) : make_pair(0, 0)), 
                    right_side = ((neg_one[j] < part.se) ? make_pair(neg_one[j] + 1, part.se) : make_pair(0, 0));
                    
                    int two_in_left = upb(all(two), left_side.se) - lwb(all(two), left_side.fi),
                        two_in_right = upb(all(two), right_side.se) - lwb(all(two), right_side.fi);
                            
                    int neg_in_left = upb(all(neg), left_side.se) - lwb(all(neg), left_side.fi), 
                        neg_in_right = upb(all(neg), right_side.se) - lwb(all(neg), right_side.fi);

                    if (two_in_left >= two_in_right && !(neg_in_left & 1)) {
                        t[two_in_left] = left_side;
                    }
                    else if (two_in_left < two_in_right && !(neg_in_right & 1)) {
                        t[two_in_right] = right_side;
                    }
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