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
const int N = 5e5 + 10;

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

    void app(int i,int x,int l2,int r2) {
        t[i].mn += x;
        t[i].s += x*(r2-l2+1);
        t[i].lz += x;
    }

    void psh(int i,int l2,int m2,int r2) {
        app(2*i, t[i].lz, l2, m2);
        app(2*i+1, t[i].lz, m2+1, r2);
        t[i].lz = 0;
    }


    void upd1(int l1, int r1, int x, int i, int l2, int r2) {
        if(l1 <= l2 && r2 <= r1) {
            app(i, x, l2, r2);
            return;
        }
        int m2=(l2+r2)/2;
        psh(i, l2, m2, r2);
        if(l1 <= m2) upd1(l1, r1, x, 2*i, l2, m2);
        if(m2 < r1) upd1(l1, r1, x, 2*i+1, m2+1, r2);
        t[i] = Merge(t[2*i] , t[2*i+1]);
    }
    void upd1(int l, int r, int val){
        upd1(l, r, val, 1, 0, n-1);
    }

    node qry1(int l1, int r1, int i, int l2, int r2) {
        if(l1<=l2&&r2<=r1)return t[i];
        int m2=(l2+r2)/2;
        psh(i,l2,m2,r2);
        node left , right;
        if(l1 <= m2) left = qry1(l1, r1, 2*i, l2, m2);
        if(m2 < r1) right = qry1(l1, r1, 2*i+1, m2+1, r2);
        return Merge(left, right);
    }
    node qry1(int l, int r){
        return qry1(l, r, 1, 0, n-1);
    }
};

int b[N],e[N],cur;
vector<int> g[N];

void dfs(int u){
    b[u] = ++cur;
    for(auto v: g[u]){
        dfs(v);
    }
    e[u] = cur;
}


void solve(){
   int n; cin >> n;
    for(int i = 0; i <= n; i++){
        g[i].clear();
    }

    int node = 1;
    vector<ar<int,3>> a(n);

    for(int i = 0; i < n; i++){
        int t; cin >> t;
        int p, x;
        if(t == 1){
            cin >> p;
            g[p].push_back(++node);
            a[i] = {t,node,0};
        }else{
            cin >> p >> x;
            a[i] = {t,p,x};
        }
    }

    cur = 0;
    dfs(1);
    int m = n;
    n = cur+1;
    
    ST st(n);
   
    for(int i = 0; i < m; i++){
        if(a[i][0] == 1){
            int u = a[i][1];
            int x = st.qry1(b[u],b[u]).s;
            st.upd1(b[u],b[u],-x);
        }else{
            int u = a[i][1], x = a[i][2];
            st.upd1(b[u],e[u],x);
        }
    }

    for(int i = 1; i <= node; i++){
        cout<<st.qry1(b[i],b[i]).s<<' ';
    }
    cout<<endl;

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

