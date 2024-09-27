
#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 998244353;
const int N = 2e5 + 10;

void solve(){
    int n; cin >> n;
    int k; cin >> k;

    vector<int> dp(n+1), s(n+1), res(n+1);
    dp[0] = 1;

    for(int i = k, sum = 0; (sum += i) <= n; i++){
        for(int j = sum; j <= n; j++){
            s[j] = dp[j - i];
            dp[j] = (dp[j] + dp[j - i]) % M;
            res[j] = (res[j] + dp[j - i]) % M;
            dp[j - i] = s[j - i];
            s[j - i] = 0;
        }
    }

    for(int i = 1; i <= n; i++){
        cout << res[i] << ' ';
    }
    cout << '\n';

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   // cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

