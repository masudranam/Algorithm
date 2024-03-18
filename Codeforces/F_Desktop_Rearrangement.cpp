#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<endl
#define all(a) (a).begin(),(a).end()
#define sz(a) (int)(a.size())
#define int   long long int
#define endl '\n'
#define ar array
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

int f(int i, int j, int n){
    return j*n + i;
}

struct node {
    int mn,s,mx,lz;
    node(){
        mn = mx = s = lz = 0;
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

    void upd(int l1,int x,int i,int l2,int r2) {
        if(l2==r2) {
            t[i].s = x;
            return;
        }
        int m2=(l2+r2)/2;
        if(l1<=m2) upd(l1, x, 2*i, l2, m2);
        else upd(l1, x, 2*i+1, m2+1, r2);
        t[i] = Merge(t[2*i], t[2*i+1]);
    }
    void upd(int l, int val){
        upd(l,val,1,0,n-1);
    }

    node qry(int l1,int r1,int i,int l2,int r2) {
        if(l2 >= l1 && r2 <= r1) return t[i];
        if(l2 > r1 || r2 < l1)return node();
        int m2=(l2+r2)/2;

        node left , right;
        if(l1 <= m2)left = qry(l1, r1, 2*i, l2, m2);
        if(m2 < r1)right = qry(l1, r1, 2*i+1, m2+1, r2);
        return Merge(left, right);
    }
    node qry(int l, int r){
        return qry(l,r,1,0,n-1);
    }
};

void solve(){
    int n, m, q;

    cin >> n >> m >> q;
    vector<int> a(n*m);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c; cin >> c;
            a[f(i,j,n)] = (c == '*');
        }
    }

    ST st(n*m);

    for(int i = 0; i < n*m; i++){
        st.upd(i,a[i]);
    }

    int tot = st.qry(0,n*m-1).s;

    while(q--){
        int i, j;
        cin >> i >> j , i--,j--;
        int x = f(i,j,n);
        if(a[x])tot--,a[x] = 0;
        else tot++, a[x] = 1;
        st.upd(x,a[x]);
        cout<<tot - st.qry(0,tot-1).s<<endl;
    }

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

