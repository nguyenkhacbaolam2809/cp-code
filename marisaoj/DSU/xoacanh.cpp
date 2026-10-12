#include <bits/stdc++.h>
#define int long long 
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ii pair<int , int >
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define file "xoacanh"
#define endl "\n"
using namespace std;
const int MAXN = 1e6 + 6;
const int maxn = 1e5 + 5;
const int INF = 1e18 + 18;
const int MOD = 1e9 + 7;

int n,m,q;
vector<int> e[maxn];
vector<ii> edge(maxn);
vector<ii> del(maxn);
vector<ii> query;
int par[maxn],sz[maxn];
vector<int> ans;

int findroot(int u) {
    if(par[u] == u) return par[u];
    return par[u] = findroot(par[u]);
}

void findunion(int u,int v) {
    int a = findroot(u);
    int b = findroot(v);
    if(a == b) return;
    if(sz[a] > sz[b]) {
        sz[a] += sz[b];
        par[b] = a;
    }
    else {
        sz[b] += sz[a];
        par[a] = b;
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
    for(int i = 1;i <= m ;i++) {
        int u,v;
        cin >> u >> v;
        edge[i] = {u,v};
    }
    while(q--) {
        int e,c;
        cin >> e >> c;
        del[e].fi = 1;
        del[e].se = c;    
        query.pb({e,c});
    }
        for(int i = 1;i <= n;i++) {
        par[i] = i;
        sz[i] = 1;
    }
    for(int i = 1;i <= m;i++) {
        if(del[i].fi == 0) {
            e[edge[i].fi].pb(edge[i].se);
            e[edge[i].se].pb(edge[i].fi);
            findunion(edge[i].fi, edge[i].se);
        } 
    }

    for(int i = query.size() - 1;i >= 0;i--) {
        ii x = query[i];
        ans.pb(sz[findroot(x.se)]);
        findunion(edge[x.fi].fi, edge[x.fi].se);
    }
    for(int i = ans.size() - 1;i >= 0;i--) {
        cout << ans[i] << '\n';
    }
    

    return 0;
}