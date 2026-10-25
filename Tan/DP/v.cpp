#include <bits/stdc++.h>
//#include <iomanip>
#define int long long 
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ii pair<int , int >
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define file "bitcoin"
#define endl "\n"
using namespace std;
const int MAXN = 1e6 + 6;
const int maxn = 1e5 + 5;
const int INF = 1e18 + 18;
const int MOD = 1e9 + 7;

int q;
void sol() {
    double long dp[55][2],a[55];
    double long x;int n;
    cin >> n >> x;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    dp[1][0] = 0;
    dp[1][1] = x;
    for(int i = 2;i <= n;i++) {
        dp[i][1] = max(dp[i - 1][1] , 
                       dp[i - 1][0] * a[i] / 0.99);
        dp[i][0] = max(dp[i - 1][0] , 
                       dp[i - 1][1] / a[i] * 0.99);
    }
    cout << fixed << setprecision(5) << dp[n][1] << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(file".inp", "r")) {
        freopen(file".inp", "r", stdin);
        freopen(file".out", "w", stdout);
    }

    cin >> q;
    while(q--) {
        sol();
    }

    return 0;
}