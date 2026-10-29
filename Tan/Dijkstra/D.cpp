#include <bits/stdc++.h>
#define int long long 
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ii pair<int , int >
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define file "diemhien"
#define endl "\n"
using namespace std;
const int MAXN = 1e6 + 6;
const int maxn = 1e5 + 5;
const int INF = 1e18 + 18;
const int MOD = 1e9 + 7;

int n,m,k;
vector<ii> g[maxn],rg[maxn];
int d1[maxn],d2[maxn];

void dijkstra(int s, int t) {
    for(int i = 1;i <= n;i++) {
        d1[i] = INF;
        d2[i] = INF;
    }
    d1[s] = 0,d2[t] = 0;
    priority_queue< ii , vector<ii> , greater<ii>> q1,q2;
    q1.push({d1[s] , s});
    q2.push({d2[t] , t});

    while(!q1.empty()) {
        int canh = q1.top().fi;
        int dinh = q1.top().se;
        q1.pop();
        if(canh > d1[dinh]) continue;
        for(auto v : g[dinh]) {
            if(d1[dinh] + v.se < d1[v.fi]) {
                d1[v.fi] = d1[dinh] + v.se;
                q1.push({d1[v.fi] , v.fi});
            }
        }
    }

    while(!q2.empty()) {
        int canh = q2.top().fi;
        int dinh = q2.top().se;
        q2.pop();
        if(canh > d2[dinh]) continue;
        for(auto v : rg[dinh]) {
            if(d2[dinh] + v.se < d2[v.fi]) {
                d2[v.fi] = d2[dinh] + v.se;
                q2.push({d2[v.fi] , v.fi});
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

    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++) {
        int u,v,c;
        cin >> u >> v >> c;
        g[u].pb({v,c});
        rg[u].pb({v,c});
    }
    dijkstra(1,n);
    //for(int i = 1;i <= n;i++)
    //    cout << i << ' ' << d1[i] << ' ' << d2[i] << '\n';

    //return 0;
    for(int i = 1;i <= k;i++) {
        int x,y;cin >> x >> y;
        int ans = INF;
        for(int j = 1;j <= n;j++) {
            if(d1[j] != INF && d2[j] != INF)ans = min(ans , 
                      x * d1[j] + y * d2[j]);
        }
        cout << ans << '\n';
    }

    return 0;
}