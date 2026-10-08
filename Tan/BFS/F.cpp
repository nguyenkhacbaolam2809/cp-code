#include <bits/stdc++.h>
//#include <locale>
#define int long long 
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ii pair<int , int >
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define file "F"
#define endl "\n"
using namespace std;
const int MAXN = 1e6 + 6;
const int maxn = 1e5 + 5;
const int INF = 1e18 + 18;
const int MOD = 1e9 + 7;

int n,s;
vector<int> e[maxn];
int dist[maxn];

void bfs() {
    for(int i = 1;i < maxn;i++) {
        dist[i] = INF;
    }
    queue<int> q;
    dist[s] = 1;
    q.push(s);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v : e[u]) {
            if(dist[u] + 1 < dist[v]) {
                dist[v] = dist[u] + 1;
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

    cin >> n >> s;
    for(int i = 1;i <= n;i++) {
        int sz;
        cin >> sz;
        for(int j = 1;j <= sz;j++) {
            int u;cin >> u;
            e[i].pb(u);
        }
    }
    bfs();
    vector<int> ans;
    for(int i = 1;i <= n;i++) {
        if(dist[i] != INF) {
            ans.pb(i);
        }   
    }
    sort(ans.begin(),ans.end());
    cout << ans.size() << '\n';
    for(int x : ans) {
        cout << x << ' ';
    }

    return 0;
}