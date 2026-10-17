#include <bits/stdc++.h>
#define int long long 
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ii pair<int , int >
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define file "bacthang"
#define endl "\n"
using namespace std;
const int MAXN = 1e6 + 6;
const int maxn = 1e5 + 5;
const int INF = 1e18 + 18;
const int MOD = 1e9 + 7;

int n,k;
int a[maxn],dp[maxn];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(file".inp", "r")) {
        freopen(file".inp", "r", stdin);
        freopen(file".out", "w", stdout);
    }

    cin >> n >> k;
    for(int i = 1;i <= k;i++) {
        int x;cin >> x;
        a[x] = 1;
    }
    dp[1] = 1;
    if(!a[2]) {
        dp[2] = 1; 
    }
    for(int i = 3;i <= n;i++) {
        if(!a[i]) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % 14062008;
        }
    }
    cout << dp[n];

    return 0;
}