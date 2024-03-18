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
    int mx;
} st[1<<19],st1[1<<19]; // for 1e6 -> 22
int n,q;

struct ST {
    void upd(int l1,int x,int i=1,int l2=0,int r2=n-1) {
        if(l2==r2) {
            st[i].mx=x;
            return;
        }
        int m2=(l2+r2)/2;
        if(l1<=m2) upd(l1,x,2*i,l2,m2);
        else upd(l1,x,2*i+1,m2+1,r2);
        st[i].mx=min(st[2*i].mx,st[2*i+1].mx);
    }

    int qry(int l1,int r1,int i=1,int l2=0,int r2=n-1) {
        if(l2>=l1&&r2<=r1)
            return st[i].mx;
        if(l2 > r1 || r2 < l1)return M*M; //This line is crazy
        int m2=(l2+r2)/2;
        return min((l1<=m2?qry(l1,r1,2*i,l2,m2):M*M),(m2<r1?qry(l1,r1,2*i+1,m2+1,r2):M*M));
    }

    void updmx(int l1,int x,int i=1,int l2=0,int r2=n-1) {
        if(l2==r2) {
            st1[i].mx=x;
            return;
        }
        int m2=(l2+r2)/2;
        if(l1<=m2) updmx(l1,x,2*i,l2,m2);
        else updmx(l1,x,2*i+1,m2+1,r2);
        st1[i].mx=max(st1[2*i].mx,st1[2*i+1].mx);
    }

    int qrymx(int l1,int r1,int i=1,int l2=0,int r2=n-1) {
        if(l2>=l1&&r2<=r1)
            return st1[i].mx;
        if(l2 > r1 || r2 < l1)return 0; //This line is crazy
        int m2=(l2+r2)/2;
        return max((l1<=m2?qrymx(l1,r1,2*i,l2,m2):0),(m2<r1?qrymx(l1,r1,2*i+1,m2+1,r2):0));
    }
    
};

void solve(){
    cin >> n >> q;
    n++;

    vector<int> a(n),b(n);
    for(int i = 1; i < n; i++){
        cin >> a[i];
    }
    for(int i = 1; i < n; i++){
        cin >> b[i];
    }

    vector<int> ps(n),s(n);

    for(int i = 1; i < n; i++){
        ps[i] = ps[i-1]+(b[i]-a[i]);
        s[i] = s[i-1] + max(0ll,b[i]-a[i]);
    }

    ST st;

    for(int i = 1; i < n; i++){
        st.upd(i,ps[i]);
        st.updmx(i,ps[i]);
    }

    while(q--){
        int l, r;
        cin >> l >> r;
        int x = st.qry(l,r);
        int y = ps[r]-ps[l-1];
        if(ps[l-1] > x || y != 0){
            cout<<-1<<endl;
        }else{
            cout<<st.qrymx(l,r)-ps[l-1]<<endl;
        }
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

