#include <bits/stdc++.h>
#define int long long 
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ii pair<int , int >
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define file "dayso1dainhat"
#define endl "\n"
using namespace std;
const int MAXN = 1e6 + 6;
const int maxn = 1e5 + 5;
const int INF = 1e18 + 18;
const int MOD = 1e9 + 7;

int a[maxn],f[maxn],dp[maxn];
int n,ans;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(file".inp", "r")) {
        freopen(file".inp", "r", stdin);
        freopen(file".out", "w", stdout);
    }

    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        if(a[i] == 1) {
            dp[i] = dp[i - 1] + 1;
        }
        else {
            dp[i] = 0;
        }
    }
    for(int  i= n;i >= 1;i--) {
        if(a[i] == 1) {
            f[i] = f[i + 1] + 1; 
        }
        else f[i] = 0;
    }
    for(int i = 1;i <= n;i++) {
        ans = max(ans , dp[i - 1] + f[i + 1]);
        //cout << f[i] << ' ';
    }
    cout << ans;



    return 0;
}