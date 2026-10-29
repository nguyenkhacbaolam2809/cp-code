#include <bits/stdc++.h>
#define int long long 
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ii pair<int , int >
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define file "centre28"
#define endl "\n"
using namespace std;
const int MAXN = 1e6 + 6;
const int maxn = 1e5 + 5;
const int INF = 1e18 + 18;
const int MOD = 1e9 + 7;

int n,m;
vector<ii> g[MAXN];
int dist1[MAXN],dist2[MAXN];

void dijkstra() {
    for(int i = 1;i <= n;i++) {
        dist1[i] = INF;
        dist2[i] = INF;
    }
    priority_queue<ii , vector < ii > , greater < ii > > q1,q2;
    dist1[1] = 0;dist2[n] = 0;
    q1.push({dist1[1] , 1});
    q2.push({dist2[n] , n});
    while(!q1.empty()) {
        int canh = q1.top().fi;
        int dinh = q1.top().se;
        q1.pop();
        if(canh > dist1[dinh]) continue; 
        for(auto v : g[dinh]) {
            if(dist1[dinh] + v.se < dist1[v.fi]) {
                dist1[v.fi] = dist1[dinh] + v.se;
                q1.push({dist1[v.fi] , v.fi});
            }
        }
    }
    while(!q2.empty()) {
        int canh = q2.top().fi;
        int dinh = q2.top().se;
        q2.pop();
        if(canh > dist2[dinh]) continue; 
        for(auto v : g[dinh]) {
            if(dist2[dinh] + v.se < dist2[v.fi]) {
                dist2[v.fi] = dist2[dinh] + v.se;
                q2.push({dist2[v.fi] , v.fi});
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
        int x,y,d;
        cin >> x >> y >> d;
        g[x].pb({y,d});
        g[y].pb({x,d});
    }
    dijkstra();

    return 0;
}