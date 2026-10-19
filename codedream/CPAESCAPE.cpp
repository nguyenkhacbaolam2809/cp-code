#include <bits/stdc++.h>
#define int long long 
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ii pair<int , int >
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define file "mecung"
#define endl "\n"
using namespace std;
const int MAXN = 1e6 + 6;
const int maxn = 1e5 + 5;
const int INF = 1e18 + 18;
const int MOD = 1e9 + 7;

int n,m,temp = INF;
ii s,t;
char grid[105][105];
int dist[105][105];
ii trace[105][105];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void bfs() {
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            dist[i][j] = INF;
        }
    }
    dist[s.fi][s.se] = 0;
    queue<ii> q;
    q.push(s);
    while(!q.empty()) {
        ii u = q.front();
        q.pop();
        for(int i = 0;i < 4;i++) {
            ii v;
            v.fi = u.fi + dx[i];
            v.se = u.se + dy[i];
            if(v.fi >= 1 && v.se >= 1 && 
               v.fi <= n && v.se <= m && 
               grid[v.fi][v.se] == '.' && 
               dist[u.fi][u.se] + 1 < dist[v.fi][v.se]) {
                    dist[v.fi][v.se] = dist[u.fi][u.se] + 1;
                    q.push(v);
                    trace[v.fi][v.se] = u;
               }
        }
    }
}

void findpath() {
    vector<ii> ans;
    ii cur = t;
    while(cur != s) {
        ans.pb(cur);
        cur = trace[cur.fi][cur.se];
    }
    ans.pb(s);
    reverse(ans.begin(),ans.end());
    for(auto x : ans) {
        cout << x.fi << ' '  << x.se << '\n';
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
            if(grid[i][j] == 'E') {
                s.fi = i;s.se = j;
            }
        }
    }
    if(s.fi == 1 || s.se == 1 || s.fi == n || s.se == m ) {
        cout << 0;
        return 0;
    }
    bfs();
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(grid[i][j] == '.' && dist[i][j] != INF) {
                if(i == 1 || j == 1 || i == n || j == m ) {
                    if(dist[i][j] < temp) {
                        temp = dist[i][j];
                        t.fi = i;
                        t.se = j;
                    }
                    //cout << i << ' ' << j;
                    // cout << '\n';
                }
            }
        }
    }
    //cout << t.fi << ' ' << t.se;
    if(temp == INF) cout << "NO";
    else {
        cout << "YES" << '\n';
        findpath();
    }

    return 0;
}