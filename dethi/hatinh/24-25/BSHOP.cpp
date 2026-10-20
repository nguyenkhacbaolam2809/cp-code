#include <bits/stdc++.h>
#define int long long 
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ii pair<int , int >
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define file "BSHOP"
#define endl "\n"
using namespace std;
const int MAXN = 1e6 + 6;
const int maxn = 1e5 + 5;
const int INF = 1e18 + 18;
const int MOD = 1e9 + 7;

int n,q;
ii a[2 * maxn];
int b[2 * maxn];
int seg[MAXN];

void build(int id,int l,int r) {
    if(l == r) {
        seg[id] = a[l].se;
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2,l,mid);
    build(id * 2 + 1,mid + 1,r);
    seg[id] = max(seg[id * 2] ,seg[id * 2 + 1]);
}
int get(int id,int l,int r,int u,int v) {
    if(v < l || r < u) return -INF;
    if(u <= l && r <= v) return seg[id];
    int mid = (l + r) / 2;
    int t1 = get(id * 2,l,mid,u,v);
    int t2 = get(id * 2 + 1,mid + 1,r,u,v);
    return max(t1,t2);
}

int sol(int x,int y) {
    // lower bound x 
    // upper bound y - 1
    auto it1 = lower_bound(b + 1,b + n + 1,x);
    auto it2  = upper_bound(b + 1 , b + n + 1,y);
    it2--;
    if(it1 == b + n + 2 || it2 == b + n + 2) return 0;
    return get(1,1,n,it1 - b,it2 - b);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(file".inp", "r")) {
        freopen(file".inp", "r", stdin);
        freopen(file".out", "w", stdout);
    }

    cin >> n;
    // vi la gia ban
    // si la so nguoi yeu thich 
    for(int i = 1;i <= n;i++) {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a + 1,a + n + 1);
    for(int i = 1;i <= n;i++) {
        b[i] = a[i].fi;
    }
    build(1,1,n);
    cin >> q;
    while(q--) {
        int x,y;cin >> x >> y;
        int ans = sol(x,y);
        if(ans == -INF) cout << 0 << '\n';
        else cout << ans << '\n';
    }

    return 0;
}