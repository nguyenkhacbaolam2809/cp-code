#include <bits/stdc++.h>
#define int long long 
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ii pair<int , int >
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define file "dichuyen"
#define endl "\n"
using namespace std;
const int MAXN = 1e6 + 6;
const int maxn = 1e5 + 5;
const int INF = 1e18 + 18;
const int MOD = 1e9 + 7;

int n,m,k,q;
int dist[maxn],dp[maxn];
vector<ii> g[200];
vector<ii> query;

void dijkstra(int s,int t) {
    for(int i = 1;i <= n;i++) {
        dist[i] = INF;
        dp[i] = INF;
    }
    priority_queue< ii , vector<ii> , greater<ii> > q;
    dist[s] = 0;dp[s] = 0;
    q.push({dist[s] , s});
    while(!q.empty()) {
        int canh = q.top().fi;
        int dinh = q.top().se;
        q.pop();
        if(canh > dist[dinh]) continue;
        for(auto v : g[dinh]) {
            if(dist[dinh] + v.se < dist[v.fi]) {
                dist[v.fi] = dist[dinh] + v.se;
                dp[v.fi] = dp[dinh] + 1;
                q.push({dist[v.fi] , v.fi});
            }
            else if(dist[dinh] + v.se == dist[v.fi]) {
                dp[v.fi] = min(dp[v.fi] , dp[dinh] + 1);
            }
        }
    }

    if(dist[t] == INF) {
        cout << -1;
    }
    else {
        cout << dist[t] << ' ' << dp[t];
    }
    cout << '\n';

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(file".inp", "r")) {
        freopen(file".inp", "r", stdin);
        freopen(file".out", "w", stdout);
    }

    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int u,v,c;
        cin >> u >> v >> c;
        g[u].pb({v,c});
    }
    cin >> k >> q;
    while(q--) {
        int x,y;
        cin >> x >> y;
        dijkstra(x,y);
    }

    return 0;
}