#include <bits/stdc++.h>
#define int long long 
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ii pair<int , int >
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define file "chonxu2"
#define endl "\n"
using namespace std;
const int MAXN = 1e6 + 6;
const int maxn = 1e5 + 5;
const int INF = 1e18 + 18;
const int MOD = 1e9 + 7;

int n,t,s,a[105];
int dp[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(file".inp", "r")) {
        freopen(file".inp", "r", stdin);
        freopen(file".out", "w", stdout);
    }

    cin >> n >> s;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        t += a[i];
    }
    // dinh nghia dp[i] la so cach chon khac nhau de tao ra tong i
    dp[0] = 1;
    for(int i = 1;i <= n;i++) {
        for(int j = a[i];j <= s;j++) {
            dp[j] = ( dp[j] + dp[j - a[i]]) % MOD;
        }
    }
    // for(int i = 0;i <= t;i++) {
    //     cout << dp[i] << ' ';
    // }
    cout << dp[s];

    return 0;
}