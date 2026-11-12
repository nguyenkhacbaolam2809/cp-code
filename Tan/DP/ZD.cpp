#include <bits/stdc++.h>
#define int long long 
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ii pair<int , int >
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define file "chiakeo"
#define endl "\n"
using namespace std;
const int MAXN = 1e6 + 6;
const int maxn = 1e5 + 5;
const int INF = 1e18 + 18;
const int MOD = 1e9 + 7;

int n;
int a[maxn], pre[maxn] , dp[101][maxn],ans;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(file".inp", "r")) {
        freopen(file".inp", "r", stdin);
        freopen(file".out", "w", stdout);
    }

    cin >> n;
    ans = INF;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    // goi dp[i][j] la co the tao 1 tong dung bang j xuat phat tu 1 den i hay khong
    // chu y den kich thuoc cua mang dp 2 chieu 
    dp[0][0] = 1;
    for(int i = 1;i <= n;i++) {
        for(int j = 0;j <= pre[n];j++) {
            if(a[i] <= j) {
                dp[i][j] = max(dp[i - 1][j - a[i]] , dp[i - 1][j] );
            }
            else { 
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    for(int i = 0;i <= pre[n];i++) {
        if(dp[n][i] == 1)  ans = min(ans ,abs(2 * i  - pre[n]));
    }
    // for(int i = 1;i <= n;i++) {
    //     for(int j = 0;j <= 9;j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    cout << ans;

    return 0;
}