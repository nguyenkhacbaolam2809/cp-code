#include <bits/stdc++.h>
#define int long long 
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ii pair<int , int >
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define file "fpath"
#define endl "\n"
using namespace std;
const int MAXN = 1e6 + 6;
const int maxn = 1e5 + 5;
const int INF = 1e18 + 18;
const int MOD = 1e9 + 7;

int n,m;
vector<ii> g[maxn];
int dist[maxn];

bool bfs(int x) {
    for(int i = 1;i <= n;i++) {
        dist[i] = INF;
    }
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto v : g[u]) {
            if(v.se >= x && dist[u] + 1 < dist[v.fi]) {
                dist[v.fi] = dist[u] + 1;
                q.push(v.fi);
            }
        }
    }
    for(int i = 1;i <= n;i++) {
        if(dist[i] == INF) {
            return false;
        }
    }
    return true;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(file".inp", "r")) {
        freopen(file".inp", "r", stdin);
        freopen(file".out", "w", stdout);
    }

    cin >> n >> m;
    int l = INF,r = -INF,ans = -1;
    for(int i = 1;i <= m;i++) {
        int u,v,c;
        cin >> u >> v >> c;
        g[u].pb({v,c});
        g[v].pb({u,c});
        l = min(l , c);
        r = max(r , c);
    }
    while(l <= r) {
        int mid = (l + r) / 2;
        if(bfs(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid -1;
    }
    cout << ans;
    

    return 0;
}