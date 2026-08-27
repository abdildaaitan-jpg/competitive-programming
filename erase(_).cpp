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


void solve() {
    // vector, deque, string
    vector < int > nums = {1, 2, 3, 4, 5};
    auto it = nums.begin() + 1;
    nums.erase(it);
    // 1 3 4 5 
    nums.erase(nums.begin(), nums.begin() + 2);
    // 5

    // set map unordered_set unordered_map
    set < int > num;
    for (int i = 1; i <= 5; i++) {
        num.insert(i);
    }
    num.erase(3);
    // 1 2 4 5
    auto iter = num.begin();
    num.erase(iter);
    // 2 4 5
    num.erase(num.begin(), num.end());
    // empty set

    vector < int > v = {1, 1, 2, 2, 3, 3, 3, 4, 5};
    erase(v, 3); /* or */ v.erase(remove(all(v), 3), v.end());
    // 1 1 2 2 4 5

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