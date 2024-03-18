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

    int n; cin >> n;
    vector<int> dp(100,-1);
    dp[4] = dp[6] = dp[9] = 1;
    for(int i = 7; i < 100; i++){
        dp[i] = max(dp[i-4]+1,dp[i]);
        dp[i] = max(dp[i-6]+1,dp[i]);
        if(i >= 9)dp[i] = max(dp[i-9]+1,dp[i]);
    }

    while(n--){
        int x; cin >> x;
        if(x < 100){
            if(dp[x] == 0)cout<<-1<<endl;
            else cout<<dp[x]<<endl;
        }else{
            int ans = 0;
            for(int i = 1; i < 50; i++){
                if((x-i)%4 == 0 && dp[i] > 0){
                    ans = max(ans,(x-i)/4+dp[i]);
                }
                if((x-i)%6 == 0 && dp[i]>0){
                    ans = max(ans,(x-i)/6+dp[i]);
                }
                if((x-i)%9 == 0 && dp[i] > 0)ans = max(ans,(x-i)/9 + dp[i]);
            }
            cout<<ans<<endl;
        }
    }



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

