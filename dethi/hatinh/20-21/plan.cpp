#include <bits/stdc++.h>
#define int long long 
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ii pair<int , int >
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define file "plan"
#define endl "\n"
using namespace std;
const int MAXN = 1e6 + 6;
const int maxn = 1e5 + 5;
const int INF = 1e18 + 18;
const int MOD = 1e9 + 7;

int n,m,sz = 1;
int grid[1001][1001];
bool vis[1001][1001];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void bfs(int si,int sj) {
    queue<ii> q;
    q.push({si,sj});
    vis[si][sj] = true;

    while(!q.empty()) {
        ii u = q.front();
        q.pop();
        for(int i = 0;i < 4;i++) {
            ii v;
            v.fi = u.fi + dx[i];
            v.se = u.se + dy[i];
            if(v.fi >= 1 && v.se >= 1 && 
               v.fi <= n && v.se <= m && 
               vis[v.fi][v.se] == false && 
               grid[u.fi][u.se] == grid[v.fi][v.se]) {
                    sz++;
                    vis[v.fi][v.se] = true;
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
        string s;cin >> s;
        for(int j = 0;j < (int)s.size();j++) {
            grid[i][j + 1] = s[j] - '0';
        }
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }
    ll ans = 0,cnt = 0;
    for(int i = 1;i <= n;++i) {
        for(int j = 1;j <= m;++j) {
            if(!vis[i][j]) {
                bfs(i,j);
                cnt++;
                ans = max(ans,sz);
                sz = 1;
            }
        }
    }
    cout << cnt << '\n' << ans;

    return 0;
}