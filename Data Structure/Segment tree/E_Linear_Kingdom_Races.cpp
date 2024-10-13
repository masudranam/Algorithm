#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e6 + 10;

struct node {
    int mn,s,mx,lz;
    node(int x = 0){
        mx = 0, s = 0, lz = 0;
    }
};

struct ST {
    vector<node> t;  
    int n;
    ST(int _n){
        n = _n; t.assign(4*n + 10, node());
    }

    node Merge(node a, node b){
        node res;
        res.mx = max(a.mx , b.mx);
        return res;
    }

     void prop(int i, int l, int r){
         if(l == r || t[i].lz == 0) return;  
         t[2 * i].mx += t[i].lz;
         t[2 * i].lz += t[i].lz;
         t[2 * i + 1].mx += t[i].lz;
         t[2 * i + 1].lz += t[i].lz;
         t[i].lz = 0;  
     }

    void upd1(int L, int R, int x, int i, int l, int r) {
        prop(i,l,r);
        if(L > r || R < l || l > r) return;
        if(L <= l && r <= R) {
            t[i].lz += x;
            t[i].mx += x;
            return;
        }
        int m=(l+r)/2;
        upd1(L, R, x, 2*i, l, m);
        upd1(L, R, x, 2*i+1, m+1, r);
        t[i] = Merge(t[2*i] , t[2*i+1]);
    }

    void upd1(int L, int R, int x){
        return upd1(L,R,x,1,0,n);
    }

    node qry1(int L, int R, int i, int l, int r) {
        prop(i,l,r);
        if(L > r || R < l || l > r) return node();
        if(L<=l && r<=R){
            return t[i];
        }
        int m = (l+r)/2;
        node left , right;
         left = qry1(L, R, 2*i, l, m);
         right = qry1(L, R, 2*i+1, m+1, r);
        return Merge(left, right);
    }

    node qry1(int L, int R){
        return qry1(L,R,1,0,n);
    }    
};
 
int ps[N], dp[N];
vector<pair<int,int>>g[N];
void solve(){
    int n; cin >> n;
    int m; cin >> m;
    
    for(int i = 1; i <= n; i++){
        cin >> ps[i];
        ps[i] += ps[i - 1];
    }

    for(int i = 1; i <= m; i++){
        int l, r, p; 
        cin >> l >> r >> p;
       g[r].push_back({l, p});
    }
    ST st(n);
    for(int i = 1; i <= n; i++){
        for(auto it : g[i]){
            st.upd1(0, it.first - 1, it.second);
        }
        dp[i] = max(dp[i - 1], st.qry1(0, n).mx - ps[i]);
        st.upd1(i, i, dp[i] + ps[i]);
    }
    cout << dp[n] << '\n';

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1; 
   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}
