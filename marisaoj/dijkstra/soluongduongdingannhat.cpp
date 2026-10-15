#include <bits/stdc++.h>
#define int long long 
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ii pair<int , int >
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define file "demsoluongduongdingannhat"
#define endl "\n"
using namespace std;
const int MAXN = 1e6 + 6;
const int maxn = 1e5 + 5;
const int INF = 1e18 + 18;
const int MOD = 1e9 + 7;

int n,m,s,t;
vector<ii> g[maxn];
int dist[maxn],way[maxn];

void dijkstra() {
    for(int i = 1;i <= n;i++) {
        dist[i] = INF;
    }
    dist[s] = 0,way[s] = 1;
    priority_queue<ii , vector<ii> , greater<ii>> q;
    q.push({dist[s],s});
    while(!q.empty()) {
        int canh = q.top().fi;
        int dinh = q.top().se;
        q.pop();
        if(canh > dist[dinh]) continue;
        for(ii v : g[dinh]) {
            if(dist[dinh] + v.se < dist[v.fi]) {
                dist[v.fi] = dist[dinh] + v.se;
                way[v.fi] = way[dinh];
                q.push({dist[v.fi],v.fi});
            }
            else if(dist[dinh] + v.se == dist[v.fi]) {
                way[v.fi] = (way[v.fi] + way[dinh]) % MOD;
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

    cin >> n >> m;
    s = 1,t = n;
    for(int i = 1;i <= m;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        g[u].pb({v,w});
        g[v].pb({u,w});
    }
    dijkstra();
    cout << way[t];

    return 0;
}