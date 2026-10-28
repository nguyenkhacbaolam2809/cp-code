#include <bits/stdc++.h>
#define int long long 
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ii pair<int , int >
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define file "qbschool"
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
    for(int i = 1;i <= 5005;i++) {
        dist[i] = INF;
    }
    priority_queue<ii , vector<ii> , greater<ii> > q;
    dist[s] = 0;way[s] = 1;
    q.push({dist[s] , s});
    while(!q.empty()) {
        int canh = q.top().fi;
        int dinh = q.top().se;
        q.pop();
        if(canh > dist[dinh]) continue;
        for(auto v : g[dinh]) {
            if(dist[dinh] + v.se < dist[v.fi]) {
                dist[v.fi] = dist[dinh] + v.se;
                q.push({dist[v.fi] , v.fi});
                way[v.fi] = way[dinh];
            }
            else if(dist[dinh] + v.se == dist[v.fi]) {
                way[v.fi] = way[v.fi] + way[dinh];
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
        int k,u,v,l;
        cin >> k >> u >> v >> l;
        if(k == 1) {
            g[u].pb({v,l});
        }
        else {
            g[u].pb({v,l});
            g[v].pb({u,l});
        }
    }
    dijkstra();
    cout << dist[t] << ' ' << way[t];

    return 0;
}