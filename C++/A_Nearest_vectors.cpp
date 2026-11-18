
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
const ll maxn = 1e18 + 7;
const ll MOD = 1e9 + 7;
const ld pi = atan2(0.0, -1.0);
int gcd(int a, int b) {if (b == 0) return a; return gcd(b, a % b);}
int lcm(int a, int b) {return a / gcd(a, b) * b;}
int binpow(int a, int b) {
    int res = 1; 
    while (b > 0) { if (b & 1) res = (res * a) % MOD; a = (a * a) % MOD; b /= 2; }
    return res;
}
void up(int &x, int y) { x = max(x, y); return; }
void down(int &x, int y) { x = min(x, y); return; }

map < ld, pair < int, int >> ang;

using point = tuple < int, int, int >;

int dot(point x, point y) { return get<0>(x) * get<0>(y) + get<1>(x) * get<1>(y); }
int cross(point x, point y) { return get<0>(x) * get<1>(y) - get<1>(x) * get<0>(y); }

ld radToAng(ld rad) { return rad / pi * 180.0; }

int quad(point x) {
    if (get<0>(x) >= 0 && get<1>(x) >= 0) return 1;
    else if (get<0>(x) >= 0 && get<1>(x) <= 0) return 4;
    else if (get<0>(x) <= 0 && get<1>(x) <= 0) return 3;
    return 2;
}

int sign(int x) { return (x > 0) - (x < 0); }
int dist2(point x) { return get<0>(x) * get<0>(x) + get<1>(x) * get<1>(x); }

bool cmp(point x, point y) {
    if (quad(x) == quad(y)) {
        if (sign(cross(x, y)) == 0) return dist2(x) < dist2(y);
        return (sign(cross(x, y)) == 1);
    }
    return quad(x) < quad(y);
}


void solve() {
    int n; cin >> n;
    vector < point > p(n);

    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        p[i] = {x, y, i + 1};
    }

    sort(all(p), cmp);

    ld best = 1e18;
    pair < int, int > ans;

    for (int i = 1; i < n; i++) {
        ld angle = radToAng(atan2((ld)cross(p[i], p[i - 1]), (ld)dot(p[i], p[i - 1])));        
        
        if (angle < 0) angle += 360;
        angle = min(angle, 360 - angle);

        if (angle < best) {
            best = angle;
            ans = {get<2>(p[i]), get<2>(p[i - 1])};
        }
    }
    ld angle = radToAng(atan2((ld)cross(p[0], p[n - 1]), (ld)dot(p[0], p[n - 1])));
    
    if (angle < 0) angle += 360;
    angle = min(angle, 360 - angle);

    if (angle < best) {
        ans = {get<2>(p[0]), get<2>(p[n - 1])};
    }

    cout << ans.fi << ' ' << ans.se;
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
