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
string s;
int n;

struct node{
    int open = 0, close = 0, len = 0;
}st[1<<22];

node Merge(node a, node b){
    node res;
    int open = a.open - a.len, close = b.close - b.len;
    res.len = a.len + b.len + min(open,close);
    res.open = a.open + b.open;
    res.close = a.close + b.close;
    return res;
}

void upd(int i, int l,int r){
    if(l == r){
        if(s[l] == '('){
            st[i].open = 1;
        }else{
            st[i].close = 1;
        }
        return;
    }
    int m = (l+r)/2;
    upd(2*i,l,m);
    upd(2*i+1,m+1,r);
    st[i] = Merge(st[2*i],st[2*i+1]);
}

node qry(int i, int b, int e, int l, int r){
    if(r < b || l > e){
        node r;
        return r;
    }
    if(l >= b && r <= e){
        return st[i];
    }
    int m = (l+r)/2;
    node left,right;
    left = qry(2*i,b,e,l,m);
    if(m < r)right = qry(2*i+1,b,e,m+1,r);
    return Merge(left,right);
}

void solve(){
    cin >> s;
    n = sz(s);
    upd(1,0,n-1);
   
    int q; cin >> q;
    while(q--){
        int l, r; cin >> l >> r;
        l--, r--;
        node res = qry(1,l,r,0,n-1);
        cout<<2*res.len<<endl;
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

