#include <bits/stdc++.h>
#define int long long 
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ii pair<int , int >
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define file "khopcau"
#define endl "\n"
using namespace std;
const int MAXN = 1e6 + 6;
const int maxn = 1e5 + 5;
const int INF = 1e18 + 18;
const int MOD = 1e9 + 7;

int n,m,cnt;
vector<int> g[maxn];
int vis[maxn] , num[maxn] , low[maxn];
// num[u] cho biet thu tu duyet DFS cua cac dinh 
// low[u] cho biet gia tri num nho nhat co the di den tu u 
// bang cach di xuoi theo cac canh net lien va ket thuc nguoc khong qua 1 net dut


void dfs(int u,int p) {
    num[u] = low[u] = ++cnt;
    for(auto v : g[u]) {
        if(num[u]) low[u] = min(low[u] , num[v]);
        else {
            dfs(v , u);
            low[u] = min(low[u] , low[v]);
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

    return 0;
}