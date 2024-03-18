#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<endl
#define all(a) (a).begin(),(a).end()
#define sz(a) (int)(a.size())
#define int   long long int
#define endl '\n'
#define ar array
 
const int M = 1000000007;
const int N = 2e6 + 10;

void solve(){
   int n; cin >> n;
   int cur = 0;
   int ans[n][n];

   for(int i = 0; i < n; i += 4){
      for(int j = 0; j < n; j += 4){
         for(int x = 0; x < 4; x++){
            for(int y = 0; y < 4; y++){
               ans[i+x][j+y] = cur++;
            }
         }
      }
   }
   for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
         cout<<(ans[i][j])<<" \n"[j == n-1];
      }
   }

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;  //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

