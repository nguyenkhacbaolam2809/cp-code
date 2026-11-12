#include <bits/stdc++.h>
#define int long long 
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ii pair<int , int >
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define file "caitui"
#define endl "\n"
using namespace std;
const int MAXN = 1e6 + 6;
const int maxn = 1e5 + 5;
const int INF = 1e18 + 18;
const int MOD = 1e9 + 7;

int n,w[maxn] , v[maxn], ans,W,lim;
int dp[200][maxn + 1000];
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(file".inp", "r")) {
        freopen(file".inp", "r", stdin);
        freopen(file".out", "w", stdout);
    }

    cin >> n >> W;
    for(int i = 1;i <= n;i++) {
        cin >> w[i] >> v[i];
    }

    // dinh nghia dp[i][j] la tong gia tri lon nhat i mon do dau tien khong vuot qua j
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= W;j++) {
            // gioi han la j ?
            if(w[i] <= j) {
                dp[i][j] = max(dp[i - 1][j] , dp[i - 1][j - w[i]] + v[i]);
            }
            else dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][W];
    

    return 0;
}
