#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

map<int,map<int,int>> dp;
int n, a[N];

int get(int i, int x){
    if(dp[i][x]) return dp[i][x];

    if(x % a[i] == 0)return dp[i][x] = x / a[i];
    dp[i][x] = x / a[i] + get(i - 1, x % a[i]);
    dp[i][x] = min(dp[i][x], get(i - 1, a[i] - (x % a[i])) + (x / a[i]) + 1);
    return dp[i][x];
}

void solve(){
    cin >> n;
    int x; cin >> x;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << get(n-1, x) << '\n';
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
