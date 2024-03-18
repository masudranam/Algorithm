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

struct node{
int mn,s,mx,lz;
}st[1<<20];
int n,q,m;

struct ST{

void app(int i,int x,int l2,int r2){
st[i].mn+=x;
st[i].s+=x*(r2-l2+1);
st[i].lz+=x;
}

void psh(int i,int l2,int m2,int r2){
app(2*i,st[i].lz,l2,m2);
app(2*i+1,st[i].lz,m2+1,r2);
st[i].lz=0;
}

void upd2(int l1,int r1,int x,int i=1,int l2=0,int r2=n-1){
if(l1<=l2&&r2<=r1){
    app(i,x,l2,r2);
    return;
}
int m2=(l2+r2)/2;
psh(i,l2,m2,r2);
if(l1<=m2)upd2(l1,r1,x,2*i,l2,m2);
if(m2<r1)upd2(l1,r1,x,2*i+1,m2+1,r2);
st[i].mn=min(st[2*i].mn,st[2*i+1].mn);
st[i].s=st[2*i].s+st[2*i+1].s;
}

int qry1(int l1,int r1,int i=1,int l2=0,int r2=n-1){
if(l1<=l2&&r2<=r1)return st[i].mn;
int m2=(l2+r2)/2;
psh(i,l2,m2,r2);
return min((l1<=m2?qry1(l1,r1,2*i,l2,m2):M),(m2<r1?qry1(l1,r1,2*i+1,m2+1,r2):M));
}
};

bool ok(int x, vector<ar<int,3>> &a){
   ST st;

   for(int i = 0,j = 0; i < m; i++){
      while(j < m && a[j][0]-a[i][0] <= x){
        st.upd2(a[j][1]-1,a[j][2]-1,1);
        j++;
      }
      if(st.qry1(0,n-1) > 0)return true;
      st.upd2(a[i][1]-1,a[i][2]-1,-1);
   }
   return false;
}

void solve(){
  cin >> m >> n;
  vector<ar<int,3>> a(m);
  for(int i = 0;i  < m; i++){
    int l,r,w;
    cin >> l >> r >> w;
    a[i] = {w,l-1,r-1};
  }
  sort(all(a));
    ST st;

    int ans = M;   
    
    for(int i = 0, j = 0; i < m; i++){
         while(j < m && st.qry1(0,n-2) == 0){
            st.upd2(a[j][1],a[j][2]-1,1);
            j++;
         } 

         if(st.qry1(0,n-2) > 0){
            ans = min(ans,a[j-1][0]-a[i][0]);
         }
         st.upd2(a[i][1],a[i][2]-1,-1);
    }

    cout<<ans<<endl;
}


signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;  // cin >> t;
   for (int tc = 1; tc <= t; tc++) {
   // cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

