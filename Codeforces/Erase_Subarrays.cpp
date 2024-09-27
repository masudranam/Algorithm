#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    
    vector<vector<int>>dp(n + 1, vector<int> (x + 1, 10));
    vector<int> s(x + 1, 10);
    dp[0][0] = s[0] = 0;
 
    for(int i = 1; i <= n; i++){
        for(int j = x; j >= a[i]; j--){
            dp[i][j] = min(dp[i - 1][j - a[i]], s[j - a[i]] + 1);
            s[j] = min(s[j], dp[i][j]);
        }
    }
 
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1; 
   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}
