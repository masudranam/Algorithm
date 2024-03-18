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
    int  k, d;
    cin >> n >> k >> d;

    vector<int> a(n+1);
    n++;
    for(int i = 1; i < n; i++){
        cin >> a[i];
    }

    sort(all(a));
    ST st;
    st.upd1(0,0,1);
    
    for(int i = 1; i <= n; i++){
        int it = upper_bound(all(a),a[i]+d)-a.begin();
        if(i+k > it)continue;
        int l = min(i+k-1,it-1), r = it-1;
        if(l > r)continue;
        int x = st.qry1(i-1,i-1);
        if(x == 0)continue;
        st.upd1(l,r,1);
    }

    if(st.qry1(n-1,n-1) >= 1)cout<<"YES\n";
    else cout<<"NO\n";
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;  // cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

