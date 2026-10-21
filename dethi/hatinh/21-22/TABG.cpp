#include <bits/stdc++.h>
#define int long long 
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ii pair<int , int >
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define file "tabg"
#define endl "\n"
using namespace std;
const int MAXN = 1e6 + 6;
const int maxn = 1e5 + 5;
const int INF = 1e18 + 18;
const int MOD = 1e9 + 7;

int n,m,q;
int grid[1005][1005],dist[1005][1005],ans[1005][1005];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};;
vector<ii> pos,qe;

void bfs(int sa,int sb) {
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            dist[i][j] = INF;
        }
    }
    queue<ii> q;
    q.push({sa,sb});
    dist[sa][sb] = 0;
    while(!q.empty()) {
        ii u = q.front();
        q.pop();
        for(int i =0;i < 4;i++) {
            ii v;
            v.fi = u.fi + dx[i];
            v.se = u.se + dy[i];
            if(grid[v.fi][v.se] == grid[u.fi][u.se]) {
                if(v.fi >= 1 && v.se >= 1 && 
                   v.fi <= n && v.se <= m && 
                   dist[u.fi][u.se] < dist[v.fi][v.se]) {
                        dist[v.fi][v.se] = dist[u.fi][u.se];
                        q.push({v});
                   }
            }
            else {
                if(v.fi >= 1 && v.se >= 1 && 
                   v.fi <= n && v.se <= m && 
                   dist[u.fi][u.se] + 1 < dist[v.fi][v.se]) {
                        dist[v.fi][v.se] = dist[u.fi][u.se] + 1;
                        q.push({v});
                   }
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

    cin >> n >> m >> q;
    for(int i = 1;i <= n;i++) {
        string s;
        cin >> s;
        for(int j = 0;j < (int)s.size();j++) {
            grid[i][j + 1] = s[j];
            if(grid[i][j + 1] == '*') {
                pos.pb({i,j + 1});
            }
        }
    }
    while(q--) {
        int i,j;
        cin >> i >> j;
        qe.pb({i,j});
        ans[i][j] = INF;
    }
    for(auto x : pos) {
        bfs(x.fi,x.se);
        for(auto z : qe) {
            ans[z.fi][z.se] = min( dist[z.fi][z.se] , ans[z.fi][z.se] ) ;
        }
    }
    for(auto x : qe) {
        cout << ans[x.fi][x.se] << '\n';
    }


    return 0;
}