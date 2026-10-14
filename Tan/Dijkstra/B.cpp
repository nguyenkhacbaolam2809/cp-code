#include <bits/stdc++.h>
#define int long long 
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ii pair<int , int >
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define file "B"
#define endl "\n"
using namespace std;
const int MAXN = 1e6 + 6;
const int maxn = 1e5 + 5;
const int INF = 1e18 + 18;
const int MOD = 1e9 + 7;

int n,m,s,t;
vector<ii> g[maxn];
vector<int> dist(maxn);
vector<int> ans;
int traced [maxn] ,way[maxn],dpmin[maxn],dpmax[maxn];

void dijkstra() {
    
    for(int i = 1;i <= n;i++) {
        dist[i] = INF;
        dpmin[i] = INF;
    }
    priority_queue<ii , vector<ii> , greater<ii> > q;
    q.push({0,s}); // dist , vertex
    dist[s] = 0;way[s] = 1;
    dpmin[s] = 0;dpmax[s] = 0;
    while(!q.empty()) {
        int canh = q.top().fi;
        int dinh = q.top().se;
        q.pop();
        if(canh > dist[dinh]) continue;
        for(auto v : g[dinh]) {
            // v.fi la dinh 
            // v.se la trong so cua canh
            if(dist[dinh] + v.se < dist[v.fi]) {
                dist[v.fi] = dist[dinh] + v.se;
                q.push({dist[v.fi] , v.fi});
                traced[v.fi] = dinh;
                way[v.fi] = way[dinh];
                dpmin[v.fi] = dpmin[dinh] + 1;
                dpmax [v.fi]= dpmax[dinh] + 1;
            }else if(dist[dinh] + v.se == dist[v.fi]) {
                way[v.fi] = (way[v.fi] + way[dinh]) %MOD;
                dpmin[v.fi] = min(dpmin[dinh] + 1,
                                  dpmin[v.fi]);
                dpmax[v.fi] = max(dpmax[dinh] + 1 , 
                                    dpmax[v.fi]);
            }
        }
    }
}

void truyvet() {
    int cur = t;
    while(cur != s) {
        ans.pb(cur);
        cur = traced[cur];
    }
    ans.pb(s);
    reverse(ans.begin(),ans.end());
    for(auto x : ans) {
        cout << x << ' ';
    }


}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(file".inp", "r")) {
        freopen(file".inp", "r", stdin);
        freopen(file".out", "w", stdout);
    }
    // do dai duong di ngan nhat tu 1 den n
    // so duong di ngan nhat khac nhau tu 1 den n (mod)
    // so canh it nhat tren duong di ngan nhat tu 1 den n
    // so canh nhieu nhat tren truong di ngan nhat tu 1 den n

    cin >> n >> m;
    s = 1,t = n;
    for(int i = 1;i <= m;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        g[u].pb({v,w});
        g[v].pb({u,w});
    }
    dijkstra();
    if(dist[t] != INF) {
        cout << dist[t] << ' ' << way[t] << ' ' << dpmin[t] << ' ' << dpmax[t];
    }
    else cout << -1;

    return 0;
}