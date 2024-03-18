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
    vector<int> a(N);

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        a[x]++;
    }

    vector<int> dp(N,0);

    dp[1] = a[1];

    int ans = 0;
    for(int i = 2; i < N; i++){
        dp[i] = max(dp[i-1], dp[i-2] + a[i]*i);
        ans = max(ans, dp[i]);
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

