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
    int n, m; cin >> n >> m;
    vector<int> a(m+2);
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < m; j++){
            int x; cin >> x;
            if(x)a[j] = i;
        }
    }
    vector<vector<int>>dp(n+3,vector<int>(m+3,M));

    for(int i = 1; i <= n; i++){
        dp[i][0] = abs(a[0]-i);
    }

    for(int j = 1; j < m; j++){
        for(int i = 1; i <= n; i++){
            dp[i][j] = min({dp[i][j-1],dp[i-1][j-1],dp[i+1][j-1]})+abs(i-a[j]);
        }
    }
    int ans = M;
    for(int i = 1; i <= n; i++){
        ans = min(ans,dp[i][m-1]);
    }
    cout<<ans<<endl;
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

