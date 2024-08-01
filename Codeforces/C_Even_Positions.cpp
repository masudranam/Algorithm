#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;


struct node {
    int mn,s,mx,lz;
    node(){
        mx = -M, mn = M, s = 0, lz = -1;
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
        res.s = a.s + b.s;
        return res;
    }

    void upd(int L,int x,int i,int l,int r) {
        if(l==r) {
            t[i].s = x;
            return;
        }
        int m = (l+r)/2;
        if(L <= m) upd(L, x, 2*i, l, m);
        else upd(L, x, 2*i+1, m+1, r);
        t[i] = Merge(t[2*i], t[2*i+1]);
    }
    void upd(int l, int val){
        upd(l,val,1,0,n-1);
    }

    node qry(int L,int R,int i,int l,int r) {
        if(l >= L && r <= R) return t[i];
        if(l > R || r < L)return node();
        int m=(l+r)/2;

        node left , right;
        if(L <= m)left = qry(L, R, 2*i, l, m);
        if(m < R)right = qry(L, R, 2*i+1, m+1, r);
        return Merge(left, right);
    }
    node qry(int l, int r){
        return qry(l,r,1,0,n-1);
    }

     void prop(int i, int l, int r){
        if(t[i].lz != -1){  
            t[i].s = t[i].lz * (r - l + 1);
            if(l != r){
                t[2*i].lz = t[2*i + 1].lz = t[i].lz;
            }
            t[i].lz = -1;
        }       
    }

    void upd1(int L, int R, int x, int i, int l, int r) {
        prop(i,l,r);
        if(L > r || R < l || l > r) return;
        if(L <= l && r <= R) {
            t[i].lz = x;
            prop(i,l,r);
            return;
        }
        int m=(l+r)/2;
        upd1(L, R, x, 2*i, l, m);
        upd1(L, R, x, 2*i+1, m+1, r);
        t[i] = Merge(t[2*i] , t[2*i+1]);
    }

    void upd1(int L, int R, int x){
        return upd1(L,R,x,1,0,n-1);
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
        return qry1(L,R,1,0,n-1);
    }    
};

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    stack<int> stk;
    int res = 0;
    vector<int> vis(n);

    for(int i = n - 1; i >= 0; i --){
        if(s[i] == ')' || s[i] == '_')stk.push(i);
    }

    for(int i = 0; i < n; i++){
        if(vis[i])continue;
        while(stk.size() && stk.top() )
        vis[stk.top()] = 1;

    }
    
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

