#include <bits/stdc++.h>
#define int long long
#define ll long long
#define fi first
#define se second
#define ii pair < int , int >
#define file "ckn"
using namespace std;
const int MAXN = 1e6 + 6;
const int MOD = 1e9 + 7;
const int INF = 1e18 + 18;
const int maxn = 1e5 + 5;

int n,m,u,v,cnt;
vector<int> e[20002];

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    if(fopen(file".inp","r")) {
        freopen(file".inp","r",stdin);
        freopen(file".out","w",stdout);
    }
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    for(int i = 1;i <= n;i++) {
        cnt = 0;
        for(auto v : e[i]) {
            cnt++;
        }
        cout << cnt << '\n';
    }

    return 0;
}
