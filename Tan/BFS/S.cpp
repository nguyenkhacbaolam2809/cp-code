#include <bits/stdc++.h>
#define int long long 
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ii pair<int , int >
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define file "path"
#define endl "\n"
using namespace std;
const int MAXN = 1e6 + 6;
const int maxn = 1e5 + 5;
const int INF = 1e18 + 18;
const int MOD = 1e9 + 7;

int n,m,ans , d1[maxn] , dn[maxn];
vector<int> g[2 * maxn];
void bfs() {
    memset(d1 , 0x3f , sizeof(d1));
    memset(dn , 0x3f , sizeof(dn));
    queue<int> q1,qn;
    q1.push(1);
    qn.push(n);
    d1[1] = 0;dn[n] = 0;
    while(!q1.empty()) {
        int u = q1.front();
        q1.pop();
        for(auto v : g[u]) {
            if(d1[u] + 1 < d1[v]) {
                d1[v] = d1[u] + 1;
                q1.push(v);
            }
        }
    }
    while(!qn.empty()) {
        int u = qn.front();
        qn.pop();
        for(auto v : g[u]) {
            if(dn[u] + 1 < dn[v]) {
                dn[v] = dn[u] + 1;
                qn.push(v);
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
    for(int i = 1;i <= m;i++) {
        int u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    bfs();
    for(int i = 1;i <= n;i++) {
        if(d1[i] <= 1e9 && dn[i] <= 1e9) {
            cout << d1[i] + dn[i] << ' ';  
        }
        else {
            cout << -1 << ' ';
        }
    }


    return 0;
}