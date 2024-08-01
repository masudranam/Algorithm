#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int x1, x2, x3;
    cin >> x1 >> x2 >> x3;
    int ans = 1000;
    for(int i = min({x1,x2,x3}) - 20; i <= 20 + max({x1,x2,x3}); i++){
        ans = min(ans, abs(i - x1) + abs(i - x2) + abs(i - x3));
    }
    cout << ans << '\n';
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

