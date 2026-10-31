#include <bits/stdc++.h>
#define int long long 
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ii pair<int , int >
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define file "BANHKEO"
#define endl "\n"
using namespace std;
const int MAXN = 1e6 + 6;
const int maxn = 1e5 + 5;
const int INF = 1e18 + 18;
const int MOD = 1e9 + 7;

int n,m,k,pmin = INF,ans;
int a[1005][1005];
vector<ii> g[maxn];
vector<bool> vis(maxn,false);
void bfs(int s) {
    queue<int> q;
    vis[s] = true;
    q.push(s);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto v : g[u]) {
            if(v.se >= pmin && vis[v.fi] == false) {
                vis[v.fi] = true;
                q.push(v.fi);
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
    for(int i = 1;i <= k;i++) {
        int x;cin >> x;
        pmin = min(pmin , x);
    }
    for(int i = 1;i <= m;i++) {
        int u,v,c;
        cin >> u >> v >> c;
        g[u].pb({v,c});
        g[v].pb({u,c});
    }
    for(int i = 1;i <= n;i++) {
        if(!vis[i]) {
            ans++;
            //cout << i << ' ';
            bfs(i);
        }
    }
    cout << ans;

    return 0;
}