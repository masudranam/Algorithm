#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 1e5 + 10;

int dp[52][N];

void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> h(n), c(n);
    int s = 0;

    for(int i = 0; i < n; i++){
        cin >> c[i] >> h[i];
        s += h[i];
    }

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= s; j++){
            if(j)dp[i][j] = -M*M;
            else dp[i][j] = 0;
        }
    }
    if(c[0] == 0){
        dp[0][h[0]] = 0;
    }

    for(int i = 1; i < n; i++){
        for(int j = 0; j <= s; j++){
           // cout <<dp[i-1][j] <<' ';
            dp[i][j] = max(dp[i-1][j] + x,dp[i][j]);
            if(dp[i-1][j] + x >= c[i]){
                dp[i][j+h[i]] = max(dp[i][j+h[i]],dp[i-1][j] + x -c[i]);
            }
        }
        //cout << '\n';
    }
    int ans = 0;
    for(int i = 0; i <= s; i++){
        if(dp[n-1][i] >= 0)ans = max(ans,i);
    }
    cout << ans << '\n';
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
