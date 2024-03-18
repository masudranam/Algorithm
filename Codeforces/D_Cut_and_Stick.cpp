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

struct node {
    int x , cnt;
    node(){
        x = 0, cnt = 0;
    }
    node(int _x, int _cnt){
        x = _x, cnt = _cnt;
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
        if(a.x == b.x)res = {a.x, a.cnt + b.cnt};
        else if(a.cnt > b.cnt)res = {a.x,a.cnt - b.cnt};
        else res = {b.x, b.cnt - a.cnt};
        return res;
    }

    void upd(int l1,int x,int i,int l2,int r2) {
        if(l2==r2) {
            t[i] = {x,1};
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
    int n, q;
    cin >> n >> q;
    vector<int> g[n+1];
    ST st(n+1);

    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        st.upd(i,x);
        g[x].push_back(i);
    }

    while(q--){
        int l, r;
        cin >> l >> r;
        int m = r - l + 1;
        int x = st.qry(l,r).x;
        auto f = upper_bound(all(g[x]),r) - lower_bound(all(g[x]),l);
        cout << max(1ll, 2*f - m) << endl;
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

