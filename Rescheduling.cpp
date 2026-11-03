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

int l1, r1, l2, r2, s1, d1, s2, d2;
bool poss1 = 0, poss2 = 0;
pair < int, int > ans1, ans2;

void No() {
    cout << "-1 -1\n";
}

void check1() {
    pair < int, int > x = {l1, r1 - d1}, y = {l2 - d1, r2 - d2 - d1};
    int c1 = s1, c2 = s2 - d1;
    if (x.fi <= c1 && x.se >= c1 && y.fi <= c2 && y.se >= c2 && c1 <= c2) {
        poss1 = 1;
        ans1 = {s1, s2};
        return;
    }
    int l = max(x.fi, y.fi), r = min(x.se, y.se);
    if (l > r) return;
    int t = min(r, max(l, min(c1, c2)));

    poss1 = 1;
    ans1 = {t, t + d1};
}

void check2() {
    pair < int, int > x = {l2, r2 - d2}, y = {l1 - d2, r1 - d1 - d2};
    int c1 = s2, c2 = s1 - d2;
    if (x.fi <= c1 && x.se >= c1 && y.fi <= c2 && y.se >= c2 && c1 <= c2) {
        poss2 = 1;
        ans2 = {s2, s1};
        return;
    }
    int l = max(x.fi, y.fi), r = min(x.se, y.se);
    if (l > r) return; 
    int t = min(r, max(l, min(c1, c2)));

    poss2 = 1;
    ans2 = {t + d2, t};
}

void solve() {
    cin >> l1 >> r1 >> l2 >> r2 >> s1 >> d1 >> s2 >> d2;
    poss1 = 0; poss2 = 0;
    ans1 = {0, 0}; ans2 = {0, 0};
    check1();
    check2();

    if (poss1 && poss2) {
        int cost1 = abs(s1 - ans1.fi) + abs(s2 - ans1.se), cost2 = abs(s1 - ans2.fi) + abs(s2 - ans2.se);
        if (cost1 <= cost2) {
            cout << ans1.fi << ' ' << ans1.se << '\n';
        }
        else {
            cout << ans2.fi << ' ' << ans2.se << '\n';
        }
    }
    else if (poss1) {
        cout << ans1.fi << ' ' << ans1.se << '\n';
    }
    else if (poss2) {
        cout << ans2.fi << ' ' << ans2.se << '\n';
    }
    else {
        No();
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