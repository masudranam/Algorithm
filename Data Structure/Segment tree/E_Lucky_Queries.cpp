#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

string s;

struct node {
    int n4, n7, n47, n74, lz;
    node(int a = 0, int b = 0, int c = 0, int d = 0){
        n4 = a, n7 = b, n47 = c, n74 = d, lz = 0;
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
        res.n4 = a.n4 + b.n4;
        res.n7 = a.n7 + b.n7;
        res.n47 = max(a.n4 + b.n47, a.n47 + b.n7);
        res.n74 = max(a.n7 + b.n74, a.n74 + b.n4);
        return res;
    }

    void build(int i, int l, int r){
        if(l == r){
            if(s[l] == '4')t[i].n4 = t[i].n74 = t[i].n47 = 1;
            else t[i].n7 = t[i].n74 = t[i].n47 = 1;
        }else{
            int m = (l + r) >> 1;
            build(2 * i, l, m);
            build(2 * i + 1, m + 1, r);
            t[i] = Merge(t[2 * i], t[2 * i + 1]);
        }
    }
    void build1(){
       build(1,0, n - 1);
    }

     void prop(int i, int l, int r){
         if(t[i].lz == 0) return; 
         swap(t[i].n4, t[i].n7);
         swap(t[i].n47, t[i].n74); 
         t[i].lz = 0;
         if(l == r)return;
         t[2 * i].lz ^= 1;
         t[2 * i + 1].lz ^= 1; 
     }

    void upd1(int L, int R, int x, int i, int l, int r) {
        prop(i,l,r);
        if(L > r || R < l || l > r) return;
        if(L <= l && r <= R) {
            t[i].lz = 1;
            prop(i, l, r);
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
    int n, m;
    cin >> n >> m;
    cin >> s;
    ST st(n);
    st.build1();

    for(int i = 0; i < n; i++){
       // cout << st.qry1(0, i).n47 <<'\n';
    }
    for(int i = 0; i < m; i++){
        string t; cin >> t;
        if(t[0] == 'c')cout << st.qry1(0, n - 1).n47 << '\n';
        else{
            int l, r; cin >> l >> r , l--, r--;
            st.upd1(l, r, 1);
        }
    } 
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1; 
  // cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}
