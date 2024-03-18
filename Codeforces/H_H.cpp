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

int a[500];
int dp[405][405];
int n;
int get(int l, int r){
   if(l > r)return M;
   if(l == r)return a[l];
   if(l + 1 == r)return a[l]+a[r];

   int &ret = dp[l][r];
   //if(ret != -1) return ret;

   ret = M*M;
   for(int i = l;i < r; i++){
      ret = min(ret,get(l,i)+get(i+1,r));
   }
   return dp[l][r] = ret;
}


void solve(){
   cin >> n;
   for(int i = 0; i < n; i++){
      cin >> a[i];
   }
   memset(dp,-1,sizeof(dp));
   cout<<get(0,n-1)<<endl;
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;  
    //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

