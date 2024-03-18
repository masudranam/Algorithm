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


int dp[21][1<<20];
int f[100],pw[N],b[100];
vector<int> v;

int get(int i, int mask){
   if(i == sz(v))return mask == 0;

   int &ret = dp[i][mask];
   if(ret != -1) return ret;
   ret = get(i+1,mask);
   if(f[v[i]])ret = pw[f[v[i]]-1]*(get(i+1,mask)+get(i+1,mask^b[v[i]]))%M;
   return ret;
}

bool ok(int x){
   for(int i = 2; i*i <= x; i++){
      if(x%i == 0)return false;
   }
   return x > 1;
}

void solve(){
   int n; cin >> n;
   vector<int> p;
   for(int i = 2; i <= 80; i++){
      if(ok(i))p.push_back(i);
   }

   pw[0] = 1;
   for(int i = 1; i < N; i++){
      pw[i] = (pw[i-1]*2)%M;
   }
set<int> st;

   for(int i = 0; i < n; i++){
      int x; cin >> x;
      int xx = 0, t = 1;
      for(int j = 0; p[j] <= x; j++){
         int cur = 0;
         while(x%p[j] == 0)x/=p[j],cur = (cur^1);
         if(cur) xx = xx|(1<<j),t*=p[j];
      }
      b[t] = xx;
      f[t]++;
      st.insert(t);
   }
    v = vector<int>(all(st));

   memset(dp,-1,sizeof(dp));
  
   cout<<get(0,0)-1<<endl;
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

