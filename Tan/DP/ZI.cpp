#include <bits/stdc++.h>
#define int long long 
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ii pair<int , int >
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define file "doitien"
#define endl "\n"
using namespace std;
const int MAXN = 1e6 + 6;
const int maxn = 1e5 + 5;
const int INF = 1e18 + 18;
const int MOD = 1e9 + 7;

int n,m;
int a[maxn] , dp[105][10000];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(file".inp", "r")) {
        freopen(file".inp", "r", stdin);
        freopen(file".out", "w", stdout);
    }

    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for(int i = 1;i <= m;i++) {
        dp[0][i] = INF;
    }
    // goi dp[i][j] la so to tien it nhat voi j dong va tu menh gia a1 den ai
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            //dp[i][j] = dp[i - 1][j];
            if(j - a[i] >= 0) {
                dp[i][j] = min(dp[i - 1][j] , dp[i][j - a[i]] + 1);
            }
            else dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][m];



    return 0;
}