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

void solve(){
    int n;
    cin >> n;
    vector<int> a(n+1),dp(n+100);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int mx = 0;
    for(int i = 1; i <=n; i++){
        if(a[i]+i > n){
            mx = max(mx,dp[i]);
            continue;
        }
        dp[i+a[i]] = max(dp[i+a[i]],mx + a[i]+1);
        mx = max(dp[i],mx);
    }
  //  for(int i = 1; i <= n; i++)cout<<dp[i]<<' ';
   //cout<<endl;
    
    mx = 0;
    for(int i = 1; i <= n; i++)mx = max(dp[i],mx);
    cout<<n-mx<<endl;

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

