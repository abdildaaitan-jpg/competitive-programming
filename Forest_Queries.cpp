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

int n, q;
vector < string > tree;
vector < vector < int >> t;

void build(int n, int rowl, int coll, int rowr, int colr) {
    if (rowl == rowr && coll == colr) {
        t[rowl][coll] = tree[rowl][coll];
        return;
    }
    int rowm = (rowl + rowr) / 2, colm = (coll + colr) / 2;
    build(n << 2,     rowl,     coll,     rowm, colm);
    build(n << 2 + 1, rowl,     colm + 1, rowm, colr);
    build(n << 2 + 2, rowm + 1, coll,     rowr, colm);
    build(n << 2 + 3, rowm + 1, colm + 1, rowr, colr);
}

void solve() {
    cin >> n >> q;
    tree.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> tree[i];


    int x1, y1, x2, y2;
    while(q--) {
        cin >> x1 >> y1 >> x2 >> y2;
        
    }
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