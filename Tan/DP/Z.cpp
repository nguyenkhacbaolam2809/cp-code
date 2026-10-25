#include <bits/stdc++.h>
#define int long long 
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ii pair<int , int >
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define file "thanhvakynghi"
#define endl "\n"
using namespace std;
const int MAXN = 1e6 + 6;
const int maxn = 1e5 + 5;
const int INF = 1e18 + 18;
const int MOD = 1e9 + 7;

int n;
int dp[maxn][3];
int a[maxn],b[maxn],c[maxn];
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
    dp[1][0] = a[1];
    dp[1][1] = b[1];
    dp[1][2] = c[1];

    for(int i = 2;i <= n;i++) {
        dp[i][0] = max(dp[i - 1][1] , dp[i - 1][2]) + a[i];
        dp[i][1] = max(dp[i - 1][0] , dp[i - 1][2]) + b[i];
        dp[i][2] = max(dp[i - 1][0] , dp[i - 1][1]) + c[i];
    }
    cout << max({dp[n][1] , dp[n][2],dp[n][0]});

    return 0;
}