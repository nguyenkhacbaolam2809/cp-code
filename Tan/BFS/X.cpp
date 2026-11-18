#include <bits/stdc++.h>
#define int long long 
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ii pair<int , int >
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define file "nhatkhoivaduongditoitruong"
#define endl "\n"
using namespace std;
const int MAXN = 1e6 + 6;
const int maxn = 1e5 + 5;
const int INF = 1e18 + 18;
const int MOD = 1e9;

int n,k,dist1[505][505] , distn[505][505] ,ans;
char grid[505][505];
int dx[4] = {0,1,0,-1};
int dy[4] = {1 , 0 , -1 , 0};

void bfs(pair <int , int> di ,int dist[505][505]) {
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            dist[i][j] = MOD;
        }
    }
    dist[di.fi][di.se] = 0;
    queue< ii > q;
    q.push(di);
    while(!q.empty()) {
        ii u = q.front();
        q.pop();
        for(int i = 0;i < 4;i++){
            ii v;
            v.fi = u.fi + dx[i];
            v.se = u.se + dy[i];
            if(v.fi <= n && v.se <= n && v.fi >= 1 && v.se >= 1 && 
               dist[u.fi][u.se] + 1 < dist[v.fi][v.se] && 
               grid[v.fi][v.se] != '*' ) {
                    dist[v.fi][v.se] = dist[u.fi][u.se] + 1;
                    q.push(v);
               }
        }
    }
}

void sol() {
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            cin >> grid[i][j];
        }
    }
    ii start = {1,1} , finish = {n , n};
    bfs(start , dist1);
    bfs(finish , distn);
    if(k == 0) {
        if(dist1[n][n] != 1e9)cout << dist1[n][n] << '\n';
        else cout << -1 << '\n';
    }
    else {
        ans = dist1[n][n]; // khong nhay
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                if(grid[i][j] == '*') {
                    ii u,v;
                    for(int t = 0;t < 4;t++) {
                        u.fi = i + dx[t];
                        u.se = j + dy[t];
                        v.fi = i - dx[t];
                        v.se = j - dy[t];
                        if(u.fi <= n && u.se <= n && u.fi >= 1 && u.se >= 1 && 
                           v.fi <= n && v.se <= n && v.fi >= 1 && v.se >= 1) 
                            ans = min(ans , dist1[u.fi][u.se] + 1 + distn[v.fi][v.se]);
                    }
                }
            }
        }
        if(ans != 1e9)cout << ans << '\n';
        else cout << -1 << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(file".inp", "r")) {
        freopen(file".inp", "r", stdin);
        freopen(file".out", "w", stdout);
    }
    int test = 0;
    cin >> test;
    while(test--) {
        sol();
    }

    return 0;
}