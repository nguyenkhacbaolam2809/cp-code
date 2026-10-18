#include <bits/stdc++.h>
#define int long long 
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ii pair<int , int >
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define file "SPIN"
#define endl "\n"
using namespace std;
const int MAXN = 1e6 + 6;
const int maxn = 1e5 + 5;
const int INF = 1e18 + 18;
const int MOD = 1e9 + 7;

int m,k,n,t,ans;
int b[maxn];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(file".inp", "r")) {
        freopen(file".inp", "r", stdin);
        freopen(file".out", "w", stdout);
    }

    cin >> m >> k >> n >> t;
    for(int i = 1;i <= n;i++) {
        cin >> b[i];
    }
    sort(b,b + n + 1);
    for(int i = 0;i <= n - 1;i++) {
        if(k == 0) break;
        //int x = i,y = i + 1;
        int sz = b[i + 1] - b[i] - 1;
        if(k > sz) {
            k -= sz;
            int s = (sz * ( (b[i + 1] - 1)  + (b[i] + 1)   ) ) / 2;
            s = sz * t + s;
            ans += s;
        }
        else if(k <= sz) {
            int s = (k * ( (b[i + 1] - 1)  + (b[i] + k - 1) ) ) / 2;
            s = k * t + s;
            ans += s;
            k = 0;
        }
    }
    //if(k != 0) cout << -1;
    cout << ans;

    return 0;
}