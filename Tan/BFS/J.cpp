#include <bits/stdc++.h>
#define int long long 
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ii pair<int , int >
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define file "j"
#define endl "\n"
using namespace std;
const int MAXN = 1e6 + 6;
const int maxn = 1e5 + 5;
const int INF = 1e18 + 18;
const int MOD = 1e9 + 7;

int n,m,k,check;
ii di;bool ce;
int grid[2002][2002];
int dist[2002][2002];
vector<ii> order;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void bfs() {
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            dist[i][j] = INF;
        }
    }
    queue<ii> q;
    q.push(di);
    dist[di.fi][di.se] = 1;
    while(!q.empty()) {
        ii u = q.front();
        order.pb(u);
        q.pop();
        for(int i = 0;i < 4;i++) {
            ii v = u;
            v.fi = u.fi + dx[i];
            v.se = u.se + dy[i];
            if(v.fi >= 1 && v.se >= 1 &&
               v.fi <= n && v.se <= m && 
               grid[v.fi][v.se] == 1 && 
               dist[u.fi][u.se] + 1 < dist[v.fi][v.se]) {
                    dist[v.fi][v.se] = dist[u.fi][u.se] + 1;
                    q.push(v);
               }
        }
    }

}

void findpath() {
    for(int i = 0;i < k;i++) {
        ii cell = order[order.size() - 1 - i];
        cout << cell.fi << ' ' << cell.se << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(file".inp", "r")) {
        freopen(file".inp", "r", stdin);
        freopen(file".out", "w", stdout);
    }

    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 1 && ce == false) {
                di = {i,j};
                ce = true;
            }
        }
    }
    //cout << di.fi << ' ' << di.se;
    bfs();
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(dist[i][j] != INF) {
                //cout << dist[i][j] << ' ';
                check++;
            }
            //else cout << 0 << ' ';
        }
        //cout << '\n';
    }
    if(check <= k) {
        cout << "rotdoituyentinh";
    }
    else {
        findpath();
    }

    return 0;
}