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
} st[1<<20]; // for 1e6 -> 22
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
        st[i].mx=(st[2*i].mx|st[2*i+1].mx);
    }

    int qry(int l1,int r1,int i=1,int l2=0,int r2=n-1) {
        if(l2>=l1&&r2<=r1)
            return st[i].mx;
        if(l2 > r1 || r2 < l1)return 0; //This line is crazy
        int m2=(l2+r2)/2;
        return ((l1<=m2?qry(l1,r1,2*i,l2,m2):0)|(m2<r1?qry(l1,r1,2*i+1,m2+1,r2):0));
    }

    void app(int i,int x,int l2,int r2) {
        st[i].mn+=x;
        st[i].s+=x*(r2-l2+1);
        st[i].lz+=x;
    }

    void psh(int i,int l2,int m2,int r2) {
        app(2*i,st[i].lz,l2,m2);
        app(2*i+1,st[i].lz,m2+1,r2);
        st[i].lz=0;
    }


    void upd1(int l1,int r1,int x,int i=1,int l2=0,int r2=n-1) {
        if(l1<=l2&&r2<=r1) {
            app(i,x,l2,r2);
            return;
        }
        int m2=(l2+r2)/2;
        psh(i,l2,m2,r2);
        if(l1<=m2)upd1(l1,r1,x,2*i,l2,m2);
        if(m2<r1)upd1(l1,r1,x,2*i+1,m2+1,r2);
        st[i].mn=min(st[2*i].mn,st[2*i+1].mn);
        st[i].s=st[2*i].s+st[2*i+1].s;
    }

    int qry1(int l1,int r1,int i=1,int l2=0,int r2=n-1) {
        if(l1<=l2&&r2<=r1)return st[i].s;
        int m2=(l2+r2)/2;
        psh(i,l2,m2,r2);
        return (l1<=m2?qry1(l1,r1,2*i,l2,m2):0)+(m2<r1?qry1(l1,r1,2*i+1,m2+1,r2):0);
    }
};

void solve(){
   cin >> n;
   int k; cin >> k;
   ST st;

   for(int i = 0; i < n; i++){
    int x; cin >> x;
    st.upd(i,x);
   }
   
   int ans = 0;
   for(int i = k-1; i < n; i++){
    int x = st.qry(i-k+1,i)%2;
    ans += x;
   }
   cout<<ans<<endl;
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

