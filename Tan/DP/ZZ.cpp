#include <bits/stdc++.h>
#define int long long 
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ii pair<int , int >
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define file "xauconchungdainhat"
#define endl "\n"
using namespace std;
const int MAXN = 1e6 + 6;
const int maxn = 1e5 + 5;
const int INF = 1e18 + 18;
const int MOD = 1e9 + 7;

string a,b,s,t;
int dp[3003][3003] , n , m;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(file".inp", "r")) {
        freopen(file".inp", "r", stdin);
        freopen(file".out", "w", stdout);
    }

    cin >> a >> b;
    s = " ";
    t = " ";
    s += a;t += b;
    n = s.size();m = t.size();
    for(int i = 1;i < n;i++) {
        for(int j = 1;j < m;j++) {
            if(s[i] == t[j]) {
                dp[i][j] = max(dp[i][j] , dp[i - 1][j - 1] + 1);
            }
            else {
                dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
            }
        }
    }
    cout << dp[n - 1][m - 1];

    return 0;
}