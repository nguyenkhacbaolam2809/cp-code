#include <bits/stdc++.h>
#define int long long 
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ii pair<int , int >
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define file "H"
#define endl "\n"
using namespace std;
const int MAXN = 1e6 + 6;
const int maxn = 1e5 + 5;
const int INF = 1e18 + 18;
const int MOD = 1e9 + 7;

int dx[4] = {-2,-2,2,2};
int dy[4] = {-2,2,-2,2};
ii di , den;
int grid[10][10];
int dist[10][10];

void bfs() {
    for(int i = 1;i <= 8;i++) {
        for(int j = 1;j <= 8;j++) {
            dist[i][j] = INF;
        }
    }
    dist[di.fi][di.se] = 1;
    queue<ii> q;
    q.push(di);
    while(!q.empty()) {
        ii u = q.front();
        q.pop();
        for(int i = 0;i < 4;i++) {
            ii v;
            v.fi = u.fi + dx[i];
            v.se = u.se + dy[i];
            if(v.fi >= 1 && v.se >= 1 &&
               v.fi <= 8 && v.se <= 8 &&
               dist[u.fi][u.se] + 1 < dist[v.fi][v.se]) {
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

    cin >> di.fi >> di.se >> den.fi >> den.se;
    bfs();
    if(dist[den.fi][den.se] == INF) cout << -1;
    else cout << dist[den.fi][den.se] - 1;
    //for(int i = 1;i <= 8;i++) {
    //    for(int j = 1;j <= 8;j++) {
    //        cout << dist[i][j] << ' ';
    //    }
    //    cout << '\n';
    //}

    return 0;
}