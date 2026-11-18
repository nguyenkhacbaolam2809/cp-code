#include <bits/stdc++.h>
#define int long long 
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ii pair<int , int >
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define file "BAI2"
#define endl "\n"
using namespace std;
const int MAXN = 1e6 + 6;
const int maxn = 1e5 + 5;
const int INF = 1e18 + 18;
const int MOD = 1e9 + 7;

int n,m , tmp ,cnt , ans;
int grid[1002][1002],dist[1002][1002],vis[1002][1002];
ii trace[1005][1005];
short dx[9] = {-1 , 0 , 1 , 1 , 1 , 0 , -1 , -1};
short dy[9] = {1,1, 1, 0, -1, -1, -1, 0};
void bfs(ii go) {
    // for(int i = 1;i <= n;i++) {
    //     for(int j = 1;j <= m;j++) {
    //         dist[i][j] = INF;
    //     }
    // }
    int tong = grid[go.fi][go.se];
    queue<ii> q;
    dist[go.fi][go.se] = 0;
    q.push(go);
    // vis[go.fi][go.se] = grid[go.fi][go.se];
    while(!q.empty()) {
        ii u = q.front();
        q.pop();
        for(int i = 0;i <= 7;i++) {
            ii v;
            v.fi = u.fi + dx[i];
            v.se = u.se + dy[i];
            if(v.fi <= n && v.se <= m && v.fi >= 1 && v.se >= 1 && grid[v.fi][v.se] != 0 && 
                dist[u.fi][u.se] + 1 < dist[v.fi][v.se]) {
                dist[v.fi][v.se] = dist[u.fi][u.se] + 1;
                tong+= grid[v.fi][v.se];
                trace[v.fi][v.se] = u;
                q.push(v);
                // vis[v.fi][v.se] = vis[u.fi][u.se] + grid[v.fi][v.se];

            }
        }
    }
    ans = max(ans , tong);
}



signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(file".inp", "r")) {
        freopen(file".inp", "r", stdin);
        freopen(file".out", "w", stdout);
    }

    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin >> grid[i][j];
        }
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j<=m;j++) {
            dist[i][j] = INF;   
        }
    }

    // bfs({1,1});
    // for(int i = 1;i <= n;i++) {
    //     for(int j = 1;j <= m;j++) {
    //         cout << dist[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    for(int i = 1;i <= n;++i) {
        for(int j = 1;j <= m;j++) {
            if(dist[i][j] == INF && grid[i][j] != 0 ) {
                bfs({i,j});
            }
        }
    }
    cout << ans;

    // for(int i = 1;i <= n;i++) {
    //     for(int j = 1;j <= m;j++) {
    //        if(dist[i][j] == INF) cout << -1 << ' ';
    //        else cout << dist[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // for(int i = 1;i <= n;i++) {
    //     for(int j = 1;j <= m;j++) {
    //        if(dist[i][j] == INF) cout << -1 << ' ';
    //        else cout << vis[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }


    return 0;
}