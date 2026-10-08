#include <bits/stdc++.h>
#define int long long 
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ii pair<int , int >
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define file "C"
#define endl "\n"
using namespace std;
const int MAXN = 1e6 + 6;
const int maxn = 2e5 + 5;
const int INF = 1e18 + 18;
const int MOD = 1e9 + 7;

int n,m,s,t,u,v;
vector<int> e[maxn];
int dist[maxn];

void bfs() {
    for(int i = 1;i < maxn;i++) {
        dist[i] = INF;
    }
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        int d = q.front();
        q.pop();
        for(auto x : e[d]) {
            if(dist[d] + 1 < dist[x]) {
                q.push(x);
                dist[x] = dist[d] + 1;
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

    cin >> n >> m >> s >> t;
    for(int i = 1;i <= m;i++) {
        cin >> u >> v;  
        e[u].pb(v);
        //e[v].pb(u);
    }
    bfs();
    //for(int i = 1;i <= n;i++) cout << i << " " << dist[i] << '\n';
    if(dist[t] != INF) cout << dist[t];
    else cout << -1;

    return 0;
}