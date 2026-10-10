#include <bits/stdc++.h>
#define int long long
#define ll long long
#define fi first
#define se second
#define ii pair < int , int >
#define file "num"
using namespace std;
const int MAXN = 1e6 + 6;
const int MOD = 1e9 + 7;
const int INF = 1e18 + 18;
const int maxn = 1e5 + 5;

int n,ans,tmp;
int a[MAXN],pre[MAXN];
unordered_map < int , int > mp;

void sub1() {
    for(int i = 1;i <= n;i++) {
        tmp = 0;
        for(int j = i;j <= n;j++) {
            tmp += a[i];
            if(tmp == 0) {
                ans++;
            }
        }
    }
    cout << ans;
}

void sub2() {
    for(int i = 1;i <= n;i++) {
        mp[pre[i]]++;
    }
    for(auto x : mp) {
        cout << x.first << ' ' << x.second << '\n';
    }
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    if(fopen(file".inp","r")) {
        freopen(file".inp","r",stdin);
        freopen(file".out","w",stdout);
    }

    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    if(n <= 1) {
        sub1();
    }
    else {
        sub2();
    }

    return 0;
}
