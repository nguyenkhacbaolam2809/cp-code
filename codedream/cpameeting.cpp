#include <bits/stdc++.h>
#define int long long
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ii pair<int , int >
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define file "hoplanhdao"
#define endl "\n"
using namespace std;
const int MAXN = 1e6 + 6;
const int maxn = 1e5 + 5;
const int INF = 1e18 + 18;
const int MOD = 1e9 + 7;

int n,ans,pos;
int t[505][505];
vector<ii> e[maxn];
int dist[MAXN],trace[MAXN];

void dijkstra(int s) {
    for(int i = 1;i <= n;i++) {
        dist[i] = INF;
        trace[i] = 0;
    }
    dist[s] = 0 ;
    priority_queue<ii , vector<ii> , greater<ii> > q;
    q.push({dist[s],s});
    while(!q.empty()) {
        int canh = q.top().fi;
        int dinh = q.top().se;
        q.pop();
        if(canh > dist[dinh]) continue;
        for(auto v : e[dinh]) {
            if(dist[dinh] + v.se < dist[v.fi]) {
                dist[v.fi] = dist[dinh] + v.se;
                q.push({dist[v.fi], v.fi});
                trace[v.fi] = dinh;
            }
        }
    }
}

void findpath(int s) {
    dijkstra(s);
    for(int i = 1;i <= n;++i) {
        if(i != s) {
            vector<int> g;
            int cur = trace[i];
            g.pb(i);
            while(cur != s) {
                g.pb(cur);
                cur = trace[cur];
            }
            g.pb(s);
            for(auto v : g) cout << v << ' ';
            cout << '\n';
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

    cin >> n;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            cin >> t[i][j];
            if(i != j && t[i][j] != 0) {
                e[j].pb({i,t[i][j]});
                e[i].pb({j,t[i][j]});
            }
        }
    }
    cerr << '\n';
    ans = INF;
    for(int i = 1;i <= n;++i) {
        dijkstra(i);
        int cur = 0;
        for(int u = 1;u <= n;u++) {
            cur = max(cur,dist[u]);
        }
        if(cur < ans) {
            pos = i;
            ans = cur;
        }
    }
    cout << pos << ' ' << ans << '\n';
    findpath(pos);

    return 0;
}
