#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<endl
#define all(a) (a).begin(),(a).end()
#define sz(a) (int)(a.size())
//#define int   long long int
#define endl '\n'
#define ar array
 
const int M = 1e9 + 7;
const int N = 5e5 + 10;

void solve(){
    int n; cin >> n;
    string s[n];

    for(int i = 0; i < n; i++){
        cin >> s[i];
    }

    vector<vector<int>> dp(26, vector<int>(26,-M));

    for(int i = 0; i < n; i++){
        int begin = s[i][0] - 'a';
        int end = s[i].back() - 'a';
        for(int j = 0; j < 26; j++){
            dp[j][end] = max(dp[j][end], dp[j][begin] + sz(s[i]));
        }
        dp[begin][end] = max(dp[begin][end],sz(s[i]));
    }

    int ans = 0;
    for(int i = 0; i < 26; i++){
            ans = max(ans, dp[i][i]);
    }

    cout << ans << endl;
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

