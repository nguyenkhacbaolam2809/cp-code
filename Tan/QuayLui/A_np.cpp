#include <algorithm>
#include <bits/stdc++.h>
#define int long long 
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ii pair<int , int >
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define file "xaunhiphan1"
#define endl "\n"
using namespace std;
const int MAXN = 1e6 + 6;
const int maxn = 1e5 + 5;
const int INF = 1e18 + 18;
const int MOD = 1e9 + 7;

int n;
int x[100];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(file".inp", "r")) {
        freopen(file".inp", "r", stdin);
        freopen(file".out", "w", stdout);
    }
    cin >> n;
    for(int i = 1;i <= pow(2,n);i++) {
        do {
            for(int i = 1;i <= n;i++) {
                cout << x[i];
            }
            cout << '\n';
        }
        while(next_permutation(x + 1,x + n + 1));
    }
    return 0;
}