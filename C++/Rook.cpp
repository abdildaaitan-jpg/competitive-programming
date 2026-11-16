#include <bits/stdc++.h>

using ll = long long;
#define all(v) v.begin(), v.end()
#define fi first
#define se second
#define pb push_back
#define pf pop_front
using namespace std;
const int maxn = 1e19;

int n, m, k, B;
deque < int > N, M;
vector < pair < int, int >> t;

bool check(int n) {
    for (int i = 0; i < N.size(); ) if (N[i] > n) N.pf(); else break;
    for (int i = 0; i < M.size(); ) if (M[i] > n) M.pf(); else break;
    
    for (int i = 1; i <= k; i++) {
        if (t[i].fi > n) {
            if (N.empty()) return false;
            int sub = t[i].fi - N[0];
            N.pf();
            B -= sub;
        }
        if (t[i].se > n) {
            if (M.empty()) return false;
            int sub = t[i].se - M[0];
            M.pf();
            B -= sub;
        }
    }
    return (B >= 0);
}


void solve() {
    cin >> n >> m >> k >> B;
    
    int l = k, r = min(n, m);
    
    t.resize(k + 1);
    vector < bool > nn(n + 1, 0), mm(m + 1, 0);
    
    int x = maxn, y = maxn; 
    for (int i = 1; i <= k; i++) {
        cin >> t[i].fi >> t[i].se;
        x = min(t[i].fi, x);
        y = min(t[i].se, y);
    }

    x--; y--;
    if (x + 1 > 1) {
        for (int i = 1; i <= k; i++) t[i].fi -= x;
    }
    if (y + 1 > 1) {
        for (int i = 1; i <= k; i++) t[i].se -= y;
    }
    
    for (int i = 1; i <= k; i++) {
        nn[t[i].fi] = 1;
        mm[t[i].se] = 1;
    }  
    
    for (int i = 1; i <= n; i++) {
        if (!nn[i]) N.pb(i);
        if (!mm[i]) M.pb(i);
    }
    
    reverse(all(N)); reverse(all(M));
    
    while (l != r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    
    if (check(l)) cout << l;
    else cout << -1;
    
    // for (int i: N) cout << i << ' ';
    // cout << '\n';
    // for (int i: M) cout << i << ' ';
    return;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) 
        solve();
    return 0;
}