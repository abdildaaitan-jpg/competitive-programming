#include <bits/stdc++.h>

using ll = long long;
#define all(v) v.begin(), v.end()
#define fi first
#define se second
#define pb push_back
#define pf pop_front
using namespace std;

// vector < int > v, t;

// void build(int n, int s, int e) {
//     if (s == e) {
//         t[n] = v[s];
//         return;
//     }
//     int mid = (s + e) / 2;
//     build(n << 1, s, mid);
//     build(n << 1 | 1, mid + 1, e);
//     t[n] = t[n << 1] + t[n << 1 | 1];
// }

// void upd(int n,int s, int e, int i, int x) {
//     if (s == e) {
//         t[n] = x;
//         return;
//     }
//     int mid = (s + e) / 2;
//     if (i <= mid) upd(n << 1, s, mid, i, x);
//     else upd(n << 1 | 1, mid + 1, e, i, x);
//     t[n] = t[n << 1] + t[n << 1 | 1];
// }

// int get(int n, int s, int e, int l, int r) {
//     if (s > r || e < l) return 0;
//     if (s >= l && e <= r) return t[n];
//     int mid = (s + e) / 2;
//     return get(n << 1, s, mid, l, r) + get(n << 1 | 1, mid + 1, e, l, r);
// }

void solve() {
    int n, q;
    cin >> n >> q;
    
    vector < int > t(n + 1);
    for (int i = 1; i <= n; i++) cin >> t[i];
    
    vector < int > R(n + 1, 0), L(n + 1, 0);
    
    R[n] = t[n];
    for (int i = n - 1; i >= 1; i--) {
        if (t[i] == 0) {
            R[i] == 0;
        } 
        else {
            R[i] = t[i] + R[i + 1];
        }
    }
    
    L[1] = t[1];
    for (int i = 2; i <= n; i++) {
        if (t[i] == 0) {
            L[i] = 0;
        }
        else {
            L[i] = t[i] + L[i - 1];
        }
    }
    
    
    int l, r;
    while (q--) {
        cin >> l >> r;
        r += ((r < n) ? R[r + 1] : 0);
        l -= ((l > 1) ? L[l - 1] : 0);
        cout << l << ' ' << r << '\n';
    }
    
    
    // for (int i: R) cout << i << ' ';
    // cout << '\n';
    // for (int i: L) cout << i << ' ';
    return;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) 
        solve();
    return 0;
}