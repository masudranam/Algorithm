#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

int n;
int a[5050], b[5050];

 

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i], b[i] = a[i];
    }
    sort(b + 1, b + n + 1);

    vector<vector<int>> dp(2, vector<int> (n+2, M*M));
    for(int i = 1; i <= n; i++){
        dp[0][i] = 0;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
             int cur = (i + 1) % 2;
             dp[i%2][j] = min(abs(a[i] - b[j]) + dp[cur][j], dp[i%2][j-1]);
        }
        
    }

    int ans = M*M;
    for(int i = 1; i <= n; i++){
        ans = min(ans, dp[n%2][i]);
    }
    cout << ans << '\n';
 
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
