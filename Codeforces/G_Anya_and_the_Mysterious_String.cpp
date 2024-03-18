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

string s;

bool f(int i, int j, int x1, int x2){
   if((s[i]-'a'+x1)%26 == (s[j]-'a'+x2)%26) return true;
   else return false;
}

void solve(){
    int n, q;
    cin >> n >> q;
    cin >> s;

    set<ar<int,2>> st;

    for(int i = 1; i < n; i++){
        if(s[i] == s[i-1])st.insert({i-1,1});
        if(i > 1 && s[i] == s[i-2])st.insert({i-2,2});
    }
    

    ST sg(n);

    while(q--){
        int type; cin >> type;
        if(type == 2){
            int l, r;
            cin >> l >> r, l--, r--;
            auto it = st.lower_bound({l,0});
            if(it != st.end()){
                ar<int,2> x = *it;
                if(x[0]+x[1] <= r)cout<<"NO\n";
                else cout<<"YES\n";
            }else cout<<"YES\n";
        }else{
            int l, r, x;
            cin >> l >> r >> x, l--, r--;
            x %= 26;
            sg.upd1(l,r,x);
            
            int l1 = max(0ll,l-2), r1 = min(n-1,l+2);

            for(int k = 0; k < 2; k++){
            for(int i = l1+1; i <= r1; i++){
                st.erase({i-1,1});
                int x1 = sg.qry1(i-1,i-1).s, x2 = sg.qry1(i,i).s;
                if(f(i-1,i,x1,x2)){
                    st.insert({i-1,1});
                }
                
                if(i > 1){
                    x1 = sg.qry1(i-2,i-2).s, x2 = sg.qry1(i,i).s;
                    st.erase({i-2,2});
                    if(f(i-2,i,x1,x2))st.insert({i-2,2});
                }
            }
            l1 = max(0ll,r-2), r1 = min(n-1,r+2);
          }  
        }
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

