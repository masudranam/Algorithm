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
    int mn,s,mx,lz;
    node(){
         s = lz = 0;
         mx = 0;
         mn = M;
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
        res.mx = max(a.mx, b.mx);
        return res;
    }

    void upd(int l1,int x,int i,int l2,int r2) {
        if(l2==r2) {
            t[i].mx = x;
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


struct ST1 {
    vector<node> t;  
    int n;
    ST1(int _n){
        n = _n; t.assign(4*n + 10, node());
    }

    node Merge(node a, node b){
        node res;
        res.mn = min(a.mn, b.mn);
        return res;
    }

    void upd(int l1,int x,int i,int l2,int r2) {
        if(l2==r2) {
            t[i].mn = x;
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
    int n; cin >> n;

    vector<int> a(n),b(n),id[n+1];
    set<int> sta;

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        a[i] = x;
        id[x].push_back(i);
        sta.insert(x);
    }

    ST st(n);
    ST1 st1(n);


    for(int i = 0; i < n; i++){
        cin >> b[i];
        st.upd(i,a[i]);
        st1.upd(i,b[i]);
    }

    for(int i = 0; i < n; i++){
        if(sta.find(b[i]) == sta.end()){
            cout<<"NO\n";return;
        }
    }


    for(int i = 0; i < n; i++){
        if(a[i] == b[i])continue;

        auto it = lower_bound(all(id[b[i]]),i);

        if(it != id[b[i]].end()){
            int x = *it;
            if(st.qry(i,x).mx <= b[i] && st1.qry(i,x).mn >= b[i])continue;
        }
        if(it != id[b[i]].begin()){
            it--;
            int x = *it;
            if(st.qry(x,i).mx <=  b[i] && st1.qry(x,i).mn >= b[i])continue;
        }
        cout<<"NO\n";return;
    }

    cout<<"YES\n";
    
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

