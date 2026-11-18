#include <bits/stdc++.h>
#define int long long 
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ii pair<int , int >
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define file "meet"
#define endl "\n"
using namespace std;
const int MAXN = 1e6 + 6;
const int maxn = 1e5 + 5;
const int INF = 1e18 + 18;
const int MOD = 1e9 + 7;

int n,m,k,ans;
vector<int> g[maxn],pg[maxn];
int dist1[maxn] , distn[maxn];
int vis[maxn];
void bfs1(int di ,int den) {
    for(int i = 1;i <= n;i++) {
        dist1[i] = INF;
    }
    dist1[di] = 0;
    queue<int> q;
    q.push(di);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        if(u == den) continue;
        for(auto v : g[u]) {
            if(dist1[u] + 1 < dist1[v]) {
                dist1[v] = dist1[u] + 1;
                q.push(v);
            }
        }
    }
}
void bfsn(int di ,int den) {
    for(int i = 1;i <= n;i++) {
        distn[i] = INF;
    }
    distn[di] = 0;
    queue<int> q;
    q.push(di);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        if(u == den) continue;
        for(auto v : pg[u]) {
            if(distn[u] + 1 < distn[v]) {
                distn[v] = distn[u] + 1;
                q.push(v);
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(file".inp", "r")) {
        freopen(file".inp", "r", stdin);
        freopen(file".out", "w", stdout);
    }

    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++) {
        int u,v;
        cin >> u >> v;
        g[u].pb(v);
        pg[v].pb(u);
    }
    for(int i = 1;i <= k;i++) {
        int u,v;
        cin >> u >> v;
        bfs1(u , v);
        bfsn(v, u);
        for(int i = 1;i <= n;++i) {
            if(dist1[i] != INF && distn[i] != INF) {
                vis[i]++;
            }
        }
    }
    vector<int> d;
    for(int i = 1;i <= n;i++) {
        if(vis[i] == k) {
            ans++;
            d.pb(i);
        }
    }
    sort(all(d));
    cout << ans << '\n';
    for(auto x : d) {
        cout << x << ' ';
    }

    // for(int i = 1;i <= k;++i) {

    //     cout << i << ":" << '\n';
    //     for(int j = 1;j <= n;j++) {
    //         cout << j << ' ' << vis[j][i] << '\n';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';
    // for(int i = 1;i <= k;++i) {

    //     cout << i << ":" << '\n';
    //     for(int j = 1;j <= n;j++) {
    //         cout << j << ' ' << vis[j][i] << '\n';
    //     }
    //     cout << '\n';
    // }

    return 0;
}