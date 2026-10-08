#include <bits/stdc++.h>
#define int long long 
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ii pair<int , int >
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define file "G"
#define endl "\n"
using namespace std;
const int MAXN = 1e6 + 6;
const int maxn = 1e5 + 5;
const int INF = 1e18 + 18;
const int MOD = 1e9 + 7;

int n,m;
char grid[105][105];
int dist[105][105];
ii di , den;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void bfs() {
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            dist[i][j] = INF;
        }
    }
    queue<ii> q;
    dist[di.fi][di.se] = 1;
    q.push(di);
    while(!q.empty()) {
        ii u = q.front();
        q.pop();
        for(int i = 0;i < 4;i++) {
            ii v;
            v.fi = u.fi + dx[i];
            v.se = u.se + dy[i];
            if( v.fi >= 1 && v.se >= 1 &&  
                v.fi <= n && v.se <= m && 
                dist[u.fi][u.se] + 1 < dist[v.fi][v.se] && 
                grid[v.fi][v.se] != '*' ) {
                    dist[v.fi][v.se] = dist[u.fi][u.se] + 1;
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

    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 'C') {
                di.fi = i;di.se = j;
            }
            if(grid[i][j] == 'B') {
                den.fi = i,den.se = j;
            }
        }
    }
    bfs();
    if(dist[den.fi][den.se] == INF) cout << -1;
    else cout << dist[den.fi][den.se] - 1;
    //for(int i = 1;i <= n;i++) {
    //    for(int j = 1;j <= m;j++) {
    //        if(dist[i][j] == INF) {
    //            cout << -1 << ' ';
    //        }
    //        else cout << dist[i][j] << ' ';
    //    }
    //cout << '\n';
    //}

    return 0;
}