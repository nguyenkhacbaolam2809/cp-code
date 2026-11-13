#include <bits/stdc++.h>
#define int long long 
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ii pair<int , int >
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define file "dmzero"
#define endl "\n"
using namespace std;
const int MAXN = 1e6 + 6;
const int maxn = 1e5 + 5;
const int INF = 1e18 + 18;
const int MOD = 1e9 + 7;

int dp[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(file".inp", "r")) {
        freopen(file".inp", "r", stdin);
        freopen(file".out", "w", stdout);
    }
    int q;
    cin >> q;
    // goi dp[i] la so thao tac it nhat de chuyen so i thanh so 0
    // co the tach N thanh hai so A va B => N = max(A,B)
    // co the giam gia tri N xuong 1
    memset(dp , 0x3f , sizeof(dp));
    dp[0] = 0;
    for(int i = 1;i <= 1e6;++i) {
        // thao tac 1
        dp[i] = min(dp[i] , dp[i - 1] + 1);
        // thao tac 2
        for(int j = 1;j <= i;j++) {
            if(i * j > 1e6) break;
            else {
                dp[i * j] = min(dp[i * j] , dp[i] + 1);
            }
        }
    }
    //for(int i = 0;i <= 15;i++) cout << i << ' ' << dp[i] << '\n';
    //return 0;
    while(q--) {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }

    return 0;
}