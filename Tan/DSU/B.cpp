#include <bits/stdc++.h>
#define int long long 
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ii pair<int , int >
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define file "B"
#define endl "\n"
using namespace std;
const int MAXN = 1e6 + 6;
const int maxn = 5e5 + 5;
const int INF = 1e18 + 18;
const int MOD = 1e9 + 7;

int n,q;
int sz[maxn],par[maxn];

int findroot(int u) {
    if(par[u] == u) return u;
    return par[u] = findroot(par[u]);
}

void unionroot(int u,int v) {
    int a = findroot(u);
    int b = findroot(v);
    if(a == b) return;
    if(sz[a] > sz[b]) {
        // a la goc moi
        par[b] = a;
        sz[a] += sz[b];
    }
    else {
        par[a] = b;
        sz[b] += sz[a];
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(file".inp", "r")) {
        freopen(file".inp", "r", stdin);
        freopen(file".out", "w", stdout);
    }

    cin >> n >> q;
    for(int i = 1;i <= n;i++) {
        sz[i] = 1;
        par[i] = i;
    }
    for(int i = 1;i  <= q;i++) {
        char c;cin >> c;
        if(c == '+') {
            int u,v;
            cin >> u >> v;
            unionroot(u,v);
        }
        else {
            int u;
            cin >> u;
            cout << sz[findroot(u)] << '\n';
        }
    }
    

    return 0;
}