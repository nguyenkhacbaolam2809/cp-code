#include <bits/stdc++.h>
#define int long long 
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ii pair<int , int >
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define file "golf"
#define endl "\n"
using namespace std;
const int MAXN = 1e6 + 6;
const int maxn = 1e5 + 5;
const int INF = 1e18 + 18;
const int MOD = 1e9 + 7;

int n,m,ans = INF,cur,mind,maxd;
int val[505][505],grid[505][505],dist[505][505];
vector<ii> hole;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void bfs(int d) {
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            dist[i][j] = INF;
        }
    }
    dist[1][1] = 0;
    queue< ii > q;
    q.push({1,1});
    while(!q.empty()) {
        ii u = q.front();
        q.pop();
        for(int i = 0;i < 4;i++) {
            ii v;
            v.fi = u.fi + dx[i];
            v.se = u.se + dy[i];
            if(v.fi >= 1 && v.se >= 1 && 
               v.fi <= n && v.se <= m && 
               dist[u.fi][u.se] + 1 < dist[v.fi][v.se] && 
               abs(val[u.fi][u.se] - val[v.fi][v.se]) <= d) {
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
    mind = INF;maxd = -INF;
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin >> val[i][j];
            mind = min(mind,val[i][j]);
            maxd = max(maxd,val[i][j]);
        }
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin >> grid[i][j];
            if(grid[i][j]) {
                hole.pb({i,j});
            }
        }
    }
    int l = mind,r = maxd,mid;
    while(l <= r) {
        int mid = (l + r) / 2;
        bool check = true;
        bfs(mid);
        for(auto x : hole) {
            if(dist[x.fi][x.se] == INF) {
                check = false;
                break;
            }
        }
        if(check  == true) {
            ans = min(ans,mid);
            r = mid - 1;
        }
        else  {
            l = mid + 1;
        }
    }
    cout << ans;
    


    return 0;
}