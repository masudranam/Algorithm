#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n, l, r;
    cin >> n >> l >> r;

    vector<int> a(n+1), dp(n+1,-M);
    dp[0] = 0;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] += a[i-1];
    }
    for(int i = 1; i <= n; i++){
        dp[i] = max(dp[i], dp[i-1]);
        int l1 = 0, r1 = i;
        while(l1 < r1){
            int m = (l1+r1+1)/2;
            if(a[i]-a[m] >= l)l1 = m;
            else r1 = m-1;
        }
        if(a[i] - a[l1] >= l && a[i]-a[l1] <= r){
            dp[i] = max(dp[i], dp[l1]+1);
        }
    }
    cout << dp[n] << '\n';
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

