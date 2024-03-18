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
    vector<vector<int>>a(n,vector<int>(m));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    int ans = M*M, a0 = a[0][0];

    for(int x = 0; x < n; x++){
        for(int y = 0; y < m; y++){
            int lagbe = a[x][y] - x - y;
            if(lagbe > a0)continue;

            vector<vector<int>>dp(n,vector<int>(m,M*M));
            dp[0][0] = a0-lagbe;
            a[0][0] = lagbe;

            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    lagbe = a[0][0] + i + j;
                    if(lagbe > a[i][j])continue;
                    if(i) dp[i][j] = min(dp[i][j],dp[i-1][j] + a[i][j]-lagbe);
                    if(j) dp[i][j] = min(dp[i][j],dp[i][j-1] + a[i][j] - lagbe);
                }
            }

            ans = min(ans,dp[n-1][m-1]);
        }
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

