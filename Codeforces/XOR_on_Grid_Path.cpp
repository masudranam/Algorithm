#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

int a[22][22], n, res;
map<int,int> dp[21][21];

void dfs(int x, int y, int cur){
   cur ^= a[x][y];
   if(x + y == n + 1){
      dp[x][y][cur]++;
      return;
   }
   if(x < n)dfs(x + 1, y, cur);
   if(y < n)dfs(x, y + 1, cur);
}

void rdfs(int x, int y, int cur){
   if(x + y == n + 1){
      res += dp[x][y][cur];
      return;
   }
   if(x > 1)rdfs(x - 1, y, cur ^ a[x][y]);
   if(y > 1)rdfs(x, y - 1, cur ^ a[x][y]);
}


void solve(){
   cin >> n;
   for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
         cin >> a[i][j];
      }
   }
   dfs(1, 1, 0);
   rdfs(n, n, 0);
   cout << res << '\n';
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1; 
  // cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}