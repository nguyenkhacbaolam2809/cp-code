#include <bits/stdc++.h>
#define int long long 
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ii pair<int , int >
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define file "xucxac"
#define endl "\n"
using namespace std;
const int MAXN = 1e6 + 6;
const int maxn = 1e5 + 5;
const int INF = 1e18 + 18;
const int MOD = 1e9 + 7;

int n,a[101],lim,dp[101][maxn],ans;

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
    }
    // gọi dp[i][j] là số cách tạo ra tổng j từ 1 đến i
    dp[0][0] = 1;
    for(int i = 1;i <= n;i++) {
        lim += a[i];
        for(int j = 0;j <= lim;j++) {
            for(int k = 1;k <= a[i];k++) {
                if(j - k >= 0) {
                    dp[i][j] = dp[i][j] + dp[i - 1][j - k]; 
                }
            }
        }
    }
    for(int i = 0;i <= n;i++) {
        for(int j = 0;j <= lim;j++) {
            cerr << dp[i][j] << ' ';
            ans = max(ans , dp[i][j]);
        }
        cerr << '\n';
    }
    cout << ans;

    return 0;
}