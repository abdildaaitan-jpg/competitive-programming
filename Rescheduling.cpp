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

void No() {
    cout << "-1 -1\n";
}
void solve() {
    int l1, r1, l2, r2, s1, d1, s2, d2;
    cin >> l1 >> r1 >> l2 >> r2 >> s1 >> d1 >> s2 >> d2;
    if (r1 < l2) {
        cout << l1 << ' ' << l2 << '\n';
        return;
    }   
    if (l1 < l2) {
        int m = l1 + d1;
        if (m + d2 > r2) {
            No();
            return;
        }
    }
    else if (l2 < l1) {
        int m = l2 + d2;
        if (m + d1 > r1) {
            No();
            return;
        }
    }
    else {
        if (r1 < r2) {
            int m = l1 + d1;
            if (m + d2 > r2) {
                No();
                return;
            }
        }
        else {
            int m = l2 + d2;
            if (m + d1 > r1) {
                No();
                return;
            }
        }
    }

    pair < int, int > c1 = {l1, r1 - d1}, c2 = {l2, r2 - d2}, c;
    int min = maxn;
    for (int i = c1.fi; i <= c1.se; i++) {
        for (int l = i + d1; l <= c2.se; l++) {
            int abc = abs(s1 - i) + abs(s2 - l);
            if (abc < min) {
                min = abc;
                c = {i, l};
            }
        }
    }
    for (int i = c2.fi; i <= c2.se; i++) {
        for (int l = i + d2; l <= c1.se; l++) {
            int abc = abs(s2 - i) + abs(s1 - l);
            if (abc < min) {
                min = abc;
                c = {l, i};
            }
        }
    }
    cout << c.fi << ' ' << c.se << '\n';
    //
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