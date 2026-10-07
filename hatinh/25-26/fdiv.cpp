#include <bits/stdc++.h>
#define int long long
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ii pair < int , int >
#define file "fdiv"
using namespace std;
const int MAXN = 3e6 + 6;
const int MOD = 1e9 + 7;
const int INF = 1e18 + 18;
const int maxn = 1e5 + 5;

int t,x;
vector<int> prime;
vector<bool> p(MAXN,true);

void sieve() {
    p[0] = p[1] = false;
    for(int i = 2;i * i <= 3e6;i++) {
        if(p[i]) {
            for(int j = i * i;j <= 3e6;j+=i) {
                p[j] = false;
            }
        }
    }
    for(int i = 1;i <= 3e6;i++) {
        if(p[i]) prime.pb(i);
    }
}

void sol(int x) {
    // lowerbound i + 1
    auto it1 = lower_bound(prime.begin(),prime.end(),1 + x);
    auto it2 = lower_bound(prime.begin(),prime.end(),(*it1) + x);
    //cout << (*it1) * (*it2);
    cout << min((*it1) * (*it2)  ,( (*it1) * (*it1) * (*it1) ) ) << '\n';
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    if(fopen(file".inp","r")) {
        freopen(file".inp","r",stdin);
        freopen(file".out","w",stdout);
    }
    sieve();
    cin >> t;
    while(t--) {
        cin >> x;
        sol(x);
    }

    return 0;
}
