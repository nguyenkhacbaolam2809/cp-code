#include <bits/stdc++.h>
#define int long long 
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ii pair<int , int >
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define file "tomau"
#define endl "\n"
using namespace std;
const int MAXN = 1e6 + 6;
const int maxn = 1e5 + 5;
const int INF = 1e18 + 18;
const int MOD = 1e9 + 7;

int n;
<<<<<<< HEAD
int a[maxn],b[maxn],c[maxn];
int dp[maxn][4];
=======
int a[maxn] , b[maxn] , c[maxn];
int dp[maxn][4];

>>>>>>> 3d134dd (10/11/2026)
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(file".inp", "r")) {
        freopen(file".inp", "r", stdin);
        freopen(file".out", "w", stdout);
    }

    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
<<<<<<< HEAD
    // dp[i][j] la chi phi nho nhat son tu nha 1 den nha n
    // phai to mau j
    dp[1][1] = a[1];dp[1][2] = b[1];dp[1][3] = c[1];
    for(int i = 2;i <= n;i++) {
       dp[i][1] = min(dp[i - 1][2] + a[i],
                      dp[i - 1][3] + a[i]);
       dp[i][2] = min(dp[i - 1][1] + b[i],
                      dp[i - 1][3] + b[i]);
       dp[i][3] = min(dp[i - 1][1] + c[i],
                      dp[i - 1][2] + c[i]);
    }
    cout << min({dp[n][1],dp[n][2],dp[n][3]});
=======
    // goi dp[i][j] la chi phi son tat ca ngoi nha tu 1 den i mau thu  j
    dp[1][1] = a[1];
    dp[1][2] = b[1];
    dp[1][3] = c[1];
    for(int i = 2;i <= n;i++) {
        dp[i][1] = min(dp[i - 1][2] , dp[i - 1][3]) + a[i];
        dp[i][2] = min(dp[i - 1][1] , dp[i - 1][3]) + b[i];
        dp[i][3] = min(dp[i - 1][1] , dp[i - 1][2]) + c[i];
    }
    cout << min({dp[n][1] , dp[n][2] , dp[n][3]});
    

>>>>>>> 3d134dd (10/11/2026)
    return 0;
}