#include <bits/stdc++.h>
#define int long long 
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ii pair<int , int >
#define pii pair < int , ii >
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define file "cuutro"
#define endl "\n"
using namespace std;
const int MAXN = 1e6 + 6;
const int maxn = 1e5 + 5;
const int INF = 1e18 + 18;
const int MOD = 1e9 + 7;

int n,m,l,r;
double long ans;
vector<pair<int , ii > > g[maxn];
int dist[maxn], trace[maxn],f[maxn];

void dijkstra(int x) {
    for(int i = 1;i <= n;i++) dist[i] = INF;
    for(int i = 1;i <= n;i++) trace[i] = 0;
    priority_queue< ii , vector<ii> , greater<ii>> q;
    dist[1] = 0;
    q.push({0 , 1});
    while(!q.empty()) {
        int canh = q.top().fi;
        int dinh = q.top().se;
        q.pop();
        if(canh > dist[dinh]) continue;
        for(auto v : g[dinh]) {
            if(dist[dinh] + v.se.fi < dist[v.fi] && v.se.se >= x) {
                dist[v.fi] = dist[dinh] + v.se.fi;
                q.push({dist[v.fi] , v.fi});
                //trace[v.fi] = {dinh , v.se.fi};
                //trace[v.fi] = v.se.fi;
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
    for(int i = 1;i <= m;i++) {
        int u,v,c,w;
        cin >> u >> v >> c >> w;
        f[w] = 1;
        g[u].pb({v,{c,w}});
        g[v].pb({u,{c,w}});
    }
    for(int i = 1;i <= 1000;i++) {
        if(f[i]) {
            dijkstra(i);
            if(dist[n] != INF) ans = max((double long)ans, (double long)1e6 * i / dist[n]);
        }
    }
    cout << (int)ans;

    return 0;
}