#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    auto ok = [&](int x){
        vector<int> p(n+1), dp(n+1,-M);
        for(int i = 1; i <= n; i++){
            p[i] = (a[i] >= x) - (a[i] < x);
        }
        for(int i = 1; i <= n; i++){
            if((i - 1) % k == 0)dp[i] = max(dp[i], p[i]);
            else dp[i] = max(dp[i], dp[i-1] + p[i]);
            if(i >= k) dp[i] = max(dp[i], dp[i - k]);
        }
        return dp[n] > 0;
    };

    int l = 0, r = M;
    while(l < r){
        int m = (l + r + 1) / 2;
        if(ok(m)) l = m;
        else r = m - 1;
    }
    cout << l << '\n';
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