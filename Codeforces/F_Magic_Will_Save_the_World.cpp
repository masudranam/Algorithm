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
const int N = 3e6 + 10;



void solve(){
   int f, w;
   cin >> f >> w;

   int n; cin >> n;
   vector<int> a(n);
   int s = 0;
   for(int i = 0; i < n; i++){
      cin >> a[i];
      s += a[i];
   }

   vector<bool> dp(s+10);
   dp[0] = 1;
   for(int i = n-1; i >= 0; i--){
      for(int j = s; j >= a[i]; j--){
         dp[j] = dp[j] | (dp[j-a[i]]);
      }
   }

int ans = M;

   for(int i = 0; i <= s; i++){
      if(!dp[i])continue;
      int x = i, y = s-i;
      ans =min(ans,max((x+w-1)/w,(y+f-1)/f));
   }
cout<<ans<<endl;

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

