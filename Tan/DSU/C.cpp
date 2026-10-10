#include <bits/stdc++.h>
#define int long long 
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ii pair<int , int >
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define file "phaduong"
#define endl "\n"
using namespace std;
const int MAXN = 1e6 + 6;
const int maxn = 1e5 + 5;
const int INF = 1e18 + 18;
const int MOD = 1e9 + 7;

int n,m,q,id;
vector<int> e[maxn];
vector<ii> s(maxn);
int dist[maxn];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(file".inp", "r")) {
        freopen(file".inp", "r", stdin);
        freopen(file".out", "w", stdout);
    }

    cin >> n >> m >> q;
    for(int i = 1;i <= m;i++) {
        int u,v;
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
        s[i] = {u,v};
    }
    while(q--) {
        cin >> id;

    }

    return 0;
}