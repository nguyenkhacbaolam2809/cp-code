#include <bits/stdc++.h>
#define int long long 
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ii pair<int , int >
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define file "luuniem"
#define endl "\n"
using namespace std;
const int MAXN = 1e6 + 6;
const int maxn = 1e5 + 5;
const int INF = 1e18 + 18;
const int MOD = 1e9 + 7;

int n,k;
int a[maxn] , b[maxn],dp[1005][5000];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(file".inp", "r")) {
        freopen(file".inp", "r", stdin);
        freopen(file".out", "w", stdout);
    }
    // buc anh thu i co a[i] la dung luong cua buc anh
    // b[i] la gia tri tham my cua buc anh
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i] >> b[i];
    }
    k *= 1024;
    // dinh nghia dp[i][j] la gia tri lon nhat cua gia tri tham my tu 1 den i khong vuot qua j mb

    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= k;j++) {
            if(j - a[i] >= 0) {
                dp[i][j] = max( dp[i - 1][j] , dp[i][j - a[i]] + b[i] );
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    } 
    cout << dp[n][k];


    return 0;
}