#include <bits/stdc++.h>
#define int long long 
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ii pair<int , int >
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define file "togoornottogo"
#define endl "\n"
using namespace std;
const int MAXN = 1e6 + 6;
const int maxn = 1e5 + 5;
const int maxgrid = 2e3 + 3;
const int INF = 1e18 + 18;
const int MOD = 1e9 + 7;

int n,m,w,grid[maxgrid][maxgrid],dist1[maxgrid][maxgrid],
    distn[maxgrid][maxgrid] , ans , min1 = INF , minn = INF;
vector<ii> portal;

int dx[4] = {0 , 1 , 0 , -1};
int dy[4] = {1 , 0 , - 1, 0};

void bfs1() {
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            dist1[i][j] = INF;
        }
    }
    queue<ii> q;
    dist1[1][1] = 0;
    q.push({1,1});
    while(!q.empty()) {
        ii u = q.front();
        q.pop();
        for(int i = 0;i < 4;i++) {
            ii v;
            v.fi = u.fi + dx[i];
            v.se = u.se + dy[i];
            if(v.fi >= 1 && v.se >= 1 && v.fi <= n && v.se <= m &&
               grid[v.fi][v.se] != -1 && dist1[u.fi][u.se] + w < dist1[v.fi][v.se]) {
                    dist1[v.fi][v.se] = dist1[u.fi][u.se] + w;
                    q.push(v);
                }
        }
    }    
    

}
void bfsn() {
    for(int i = 1;i <= n;++i) {
        for(int j = 1;j <= m;++j) {
            distn[i][j] = INF;
        }
    }
    queue<ii> q;
    distn[n][m] = 0;
    q.push({n,m});
    while(!q.empty()) {
        ii u = q.front();
        q.pop();
        for(int i = 0;i < 4;i++) {
            ii v;
            v.fi = u.fi + dx[i];
            v.se = u.se + dy[i];
            if(v.fi >= 1 && v.se >= 1 && v.fi <= n && v.se <= m &&
               grid[v.fi][v.se] != -1 && distn[u.fi][u.se] + w < distn[v.fi][v.se]) {
                    distn[v.fi][v.se] = distn[u.fi][u.se] + w;
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

    cin >> n >> m >> w;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin >> grid[i][j];
            if(grid[i][j] >= 1) {
                portal.pb({i,j});
            }
        }
    }
    bfs1();bfsn();
    ans = dist1[n][m];
    // cach mac dinh khong the den 
    //voi gia tri portal thi no se luu vi tri x , y va gia tri grid[x][y]
    
    for(auto x : portal) {
        if(dist1[x.fi][x.se] != INF) {
            min1 = min(min1 , dist1[x.fi][x.se] + grid[x.fi][x.se]);
        }
        if(distn[x.fi][x.se] != INF) {
            minn = min(minn , distn[x.fi][x.se] + grid[x.fi][x.se]);
        }
    }
    ans = min(ans , min1 + minn);
    if(ans >= INF) {
        cout << -1;
    }
    else {
        cout << ans;
    }
    return 0;

}