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
int mn,s,g;
}st[1<<19];
int n,q;

struct ST{
void upd(int l1,int x,int id,int i=1,int l2=0,int r2=n-1){
  if(l2==r2){
    if(id)
    st[i].mn=x;
    else st[i].g = x;
    return;
  }

  int m2=(l2+r2)/2;
  if(l1<=m2)
    upd(l1,x,id,2*i,l2,m2);
  else upd(l1,x,id,2*i+1,m2+1,r2);
  if(id)
  st[i].mn=min(st[2*i].mn,st[2*i+1].mn);
  else st[i].g = __gcd(st[2*i].g,st[2*i+1].g);
}

int qry(int l1,int r1,int id,int i=1,int l2=0,int r2=n-1){
if(l2>=l1&&r2<=r1){
    if(id)
    return st[i].mn;
    return st[i].g;
}
if(l2 > r1 || r2 < l1){
    if(id)return M*M;
    return 0; //This line is crazy
}
    int m2=(l2+r2)/2;
if(id)
return min((l1<=m2?qry(l1,r1,id,2*i,l2,m2):M*M),(m2<r1?qry(l1,r1,id,2*i+1,m2+1,r2):M*M));
else 
return __gcd((l1<=m2?qry(l1,r1,id,2*i,l2,m2):0),(m2<r1?qry(l1,r1,id,2*i+1,m2+1,r2):0));
}
};

void solve(){
  cin >> n;
  vector<int> a(n);
  map<int,vector<int>>mp;

    ST x,y;

  for(int i = 0; i < n; i++){
    cin >> a[i];
    mp[a[i]].push_back(i);
    x.upd(i,a[i],1);
    y.upd(i,a[i],0);
  }

  cin >> q;
  while(q--){
    int l, r; cin >> l >> r;
    l--, r--;
    int mn = x.qry(l,r,1);
    int g = y.qry(l,r,0);
    if(g % mn){
        cout << r-l+1 << endl;
        continue;
    }
    int cnt = upper_bound(all(mp[mn]),r)-lower_bound(all(mp[mn]),l);
    cout << r-l+1-cnt << endl;

  }

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

