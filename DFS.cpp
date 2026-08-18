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

vector < vector < int >> graph;
vector < bool > used;

vector < int > comp_sizes;
vector < int > vertex_id;
int counting_sizes = 0, max_comp_size = 0;

void dfs(int vertex, int id) {
    used[vertex] = true;
    vertex_id[vertex] = id;
    counting_sizes++; 

    for (int to: graph[vertex]) {
        if (!used[to]) {
            dfs(to, id);
        }
    }    
}
void properOrder(int num) {
    if (num > 2) cout << "th ";
    else if (num == 2) cout << "nd ";
    else cout << "st ";
}

void solve() {
    int n, m, s;
    cin >> n >> m >> s;

    vector < int > vertexes(s);
    for (int &it: vertexes) cin >> it;

    graph.resize(n + 1);
    used.resize(n + 1, false);
    vertex_id.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    int cnt = 0, id = 0;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            cnt++; id++;
            counting_sizes = 0;
            dfs(i, id);
            comp_sizes.pb(counting_sizes);
            up(max_comp_size, counting_sizes);
        }
    }

    cout << "Counting separate components: " << cnt << '\n';
    
    for (int i = 1; i <= comp_sizes.size(); i++) {
        cout << "Size of " << i;
        properOrder(i);
        cout << "component: " << comp_sizes[i - 1] << '\n';
    }

    cout << "Maximum of this: " << max_comp_size << '\n';

    for (int it: vertexes) {
        cout << "Vertex " << it;
        cout << " is in the " << vertex_id[it];
        properOrder(vertex_id[it]);
        cout << "component" << '\n';
    }
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