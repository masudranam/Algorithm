#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

int n, m, a[1010], b[1010];
int dp[1010][1010];

int get(int i, int j){
    if(i == n)return (m - j);
    if(j == m)return (n - i);

    if(dp[i][j] != -1) return dp[i][j];
    int res = get(i+1,j+1) + 1;
    res = min(res, get(i+1,j)+1);
    res = min(res, get(i,j+1)+1);
    if(a[i] == b[j])res = min(res, get(i+1,j+1));
    return dp[i][j] = res;
}

void solve(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    memset(dp, -1 ,sizeof(dp));
    cout << get(0, 0) << '\n';

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1; //   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}
