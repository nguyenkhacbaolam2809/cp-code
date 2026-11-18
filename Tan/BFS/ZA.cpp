#include <bits/stdc++.h>
#define int long long 
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ii pair<int , int >
#define pii pair < ii , ii >
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define file "ROBOT"
#define endl "\n"
using namespace std;
const int MAXN = 1e6 + 6;
const int maxn = 1e5 + 5;
const int INF = 1e18 + 18;
const int MOD = 1e9 + 7;

int n,m;
ii den;
int grid[105][105],dist[105][105];
bool khoa[105][105][5];

ii dx[5] = {{0,0}, {0,-1}, {0,1}, {1,0}, {-1,0}};
ii dy[5] = {{0,0}, {1,0}, {-1,0}, {0,1}, {0,-1}};
// 1 len
// 2 xuong
// 3 phai 
// 4 trai

int cal(ii t) {
    if(t.se == 0) {
        return t.fi;
    }
    if(t.fi == 1) {
        return 4;
    }
    if(t.fi == 2) {
        return 3;
    }
    if(t.fi == 3) {
        return 1;
    }
    if(t.fi == 4) {
        return 2;
    }
    //return 0;
}

void bfs() {
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            dist[i][j] = INF;
        }
    }
    queue<pii> q;
    dist[1][1] = 0;
    q.push({  {1,1}  , {2 , 1} });
    khoa[1][1][2] = true;
    while(!q.empty()) {
        ii u = q.front().fi;
        ii t = q.front().se;
        q.pop();
        for(int i = 0;i < 2;i++) {
            ii v;
            if(i == 0){
                v.fi = u.fi + dx[t.fi].fi;v.se = u.se + dy[t.fi].fi;
            }
            else {
                v.fi = u.fi + dx[t.fi].se;v.se = u.se + dy[t.fi].se;
            }
            if(v.fi <= n && v.se <= m && v.fi >= 1 && v.se >= 1 && grid[v.fi][v.se] == 0 
               && !khoa[v.fi][v.se][cal({t.fi , i})] ) {
                    dist[v.fi][v.se] = min(dist[v.fi][v.se] , t.se + 1);
                    khoa[v.fi][v.se][cal({t.fi , i})] = true;
                    q.push({v, {cal({t.fi , i}) , t.se + 1} });
            }
        }
    }
    //cout << 0;
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
        for(int j =1;j <= m;j++) {
            cin >> grid[i][j];
        }
    }
    cin >> den.fi >> den.se;
    bfs();
    if(dist[den.fi][den.se] == INF) cout << 0;
    else cout << dist[den.fi][den.se];

    return 0;
}