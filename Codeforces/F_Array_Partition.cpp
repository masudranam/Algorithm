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
        st[i].mx=min(st[2*i].mx,st[2*i+1].mx);
    }

    int qry(int l1,int r1,int i=1,int l2=0,int r2=n-1) {
        if(l2>=l1&&r2<=r1)
            return st[i].mx;
        if(l2 > r1 || r2 < l1)return M; //This line is crazy
        int m2=(l2+r2)/2;
        return min((l1<=m2?qry(l1,r1,2*i,l2,m2):M),(m2<r1?qry(l1,r1,2*i+1,m2+1,r2):M));
    }
};

void solve(){
    cin >> n ;
    int a[n];
    ST st;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        st.upd(i,a[i]);
    }
    map<int,ar<int,2>>mp;
    int mx = a[n-1],last = n-1;
    for(int i = n - 1; i >= 0; i--){
        if(a[i] > mx){
            mp[mx] = {i+1,last};
            mx = a[i];
            last = i;
        }
    }
    mp[mx] = {0,last};


    mx = 0;
    for(int i = 0; i < n; i++){
        mx = max(mx,a[i]);
        if(mp.find(mx) == mp.end())continue;
        int l = mp[mx][0]-1, r = mp[mx][1]-1;
        l = max(i+1,l);
        if(l > r)continue;

        while(r-l > 0){
            int m = (l+r+1)/2;
            if(st.qry(i+1,m) >= mx)l = m;
            else r = m-1;
        }
        if(st.qry(i+1,l) == mx){
            cout<<"YES\n";
            int x = i+1, y = l-i, z = n-x-y;
            cout<<x<<' '<<y<<' '<<z<<endl;
            return;
        }
    }
    
    cout<<"NO\n";


}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

