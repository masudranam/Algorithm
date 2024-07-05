#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 998244353;
const int N = 2e5 + 10;

void solve(){
    int n; cin >> n;
    
    map<int,int> dp;
    dp[0] = 1;

    for(int i = 0; i < n; i++){
        int a; cin >> a;
        map<int,int> ndp;
        swap(ndp,dp);
        for(auto [x, y] : ndp){
            dp[a + x] = (dp[a + x] + y) % M;
            dp[abs(a + x)] = (dp[abs(a + x)] + y) % M;
        }
        auto it = dp.begin();
        it++;
        while(it != dp.end() && next(it) != dp.end()){
            it = dp.erase(it);
        }
    }
    cout << dp.rbegin()->first << '\n';
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
