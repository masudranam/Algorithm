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
    int n, m;
    cin >> n >> m;
    vector<int> dp(m+1),x(n),s(n);

    for(int i = 0; i < n; i++){
        cin >> x[i] >> s[i];
    }
    
    for(int i = m-1; i >= 0; i--){
        dp[i] = m-i;
        for(int j = 0; j < n; j++){
            int l = x[j] - s[j], r = x[j] + s[j];
            if(l <= i+1 && r > i)dp[i] = dp[i+1];
            if(l > i){
                int cost = l-(i+1);
                dp[i] = min(dp[i],cost + dp[min(m,cost+r)]);
            }
        }
    }
    cout<<dp[0] + (m == 100000)<<endl;
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;  // cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

