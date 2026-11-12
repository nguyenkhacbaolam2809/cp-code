#include <bits/stdc++.h>
#define int long long 
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ii pair<int , int >
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define file "cnum"
#define endl "\n"
using namespace std;
const int MAXN = 1e6 + 6;
const int maxn = 1e5 + 5;
const int INF = 1e18 + 18;
const int MOD = 1e9 + 7;

int n;
int a[maxn],dp[maxn][3];
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
        //dp[i][1] = dp[i][2] = INF;
    }
    // goi dp[i][j] la so bien doi it nhat
    // tu 1 den i chua so j
    if(a[1] == 1) {
        dp[1][1] = 0;
        dp[1][2] = 1;
    }
    else {
        dp[1][1] = 1;
        dp[1][2] = 0;
    }
    for(int i = 2;i <= n;i++) 
    {
        dp[i][1] = dp[i - 1][1] + (a[i] - 1);
        dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]);
        if(a[i] == 1) dp[i][2]++;
    }
    cout << min(dp[n][1] , dp[n][2]);
    //for(int i = 1;i <= n;i++) {
    //    cout <<dp[i][2] << ' ' << dp[i][1] << '\n';
    //}

    return 0;
}