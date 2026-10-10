#include <bits/stdc++.h>
#define int long long 
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ii pair<int , int >
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define file "dothihaiphia"
#define endl "\n"
using namespace std;
const int MAXN = 1e6 + 6;
const int maxn = 1e5 + 5;
const int INF = 1e18 + 18;
const int MOD = 1e9 + 7;

int n,m;bool check;
vector<int> e[maxn];
int dist[maxn];

void bfs() {
    for(int i = 1;i <= n;i++) {
        dist[i] = -1;
    }
    for(int i = 1;i <= n;i++) {

        if(dist[i] != -1) continue;

        queue<int> q;
        q.push(i);
        dist[i] = 1; // chua can to mau
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(int v : e[u]) {
                if(dist[v] == -1) {
                    dist[v] = 3 - dist[u];
                    q.push(v);
                }
                else {
                    if(dist[u] == dist[v]) {
                        cout << "NO";
                        return;
                    }
                }
            }
        }
    }
    cout << "YES";
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
        e[u].pb(v);
        e[v].pb(u);
    }
    bfs();



    return 0;
}