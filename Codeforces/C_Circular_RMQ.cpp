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
}st[1<<19];
int n,q;

struct ST{
void upd(int l1,int x,int i=1,int l2=0,int r2=n-1){
  if(l2==r2){
    st[i].mn=x;
    return;
  }
  int m2=(l2+r2)/2;
  if(l1<=m2)
    upd(l1,x,2*i,l2,m2);
  else upd(l1,x,2*i+1,m2+1,r2);
  st[i].mn=min(st[2*i].mn,st[2*i+1].mn);
}

void app(int i,int x,int l2,int r2){
st[i].mn+=x;
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
}

int qry1(int l1,int r1,int i=1,int l2=0,int r2=n-1){
if(l1<=l2&&r2<=r1)return st[i].mn;
int m2=(l2+r2)/2;
psh(i,l2,m2,r2);
return min((l1<=m2?qry1(l1,r1,2*i,l2,m2):M*M),(m2<r1?qry1(l1,r1,2*i+1,m2+1,r2):M*M));
}
};

vector<int> input(){
  string s; getline(cin,s);
  vector<int> v;
  stringstream ss(s);
  int x; 
  while(ss>>x)v.push_back(x);
  return v;
}

void solve(){

    cin >> n;
    ST st;

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        st.upd(i,x);
    }
  cin >> q;
   string s; getline(cin,s);
    while(q--){
    vector<int> v = input();
		if(sz(v) == 3){
        int l = v[0], r = v[1], d = v[2];
            if(l > r)st.upd2(l,n-1,d),st.upd2(0,r,d);
            else st.upd2(l,r,d);
        }else{
        int l = v[0], r = v[1];
            if(l > r)cout<<min(st.qry1(l,n-1),st.qry1(0,r)) << endl;
            else cout << st.qry1(l,r) << endl;
        }
    }

}

signed main() {
   //ios_base::sync_with_stdio (0);
   //cin.tie (0);

   int t = 1;   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

