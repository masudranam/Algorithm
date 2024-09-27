#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e8 + 0;
const int N = 2e5 + 10;

int n1, n2,K1, K2;
int dp[101][101][11][11];

int get(int i, int j, int k1, int k2){
    if(i == n1 && j == n2){
        return 1;
    }
    int &res = dp[i][j][k1][k2];
    if(res != -1) return res;
    res = 0;
    if(k1 && i < n1)res = (res + get(i+1,j,k1-1,K2)) % M;
    if(k2 && j < n2) res = (res + get(i,j+1,K1,k2-1)) % M;
    return res;
}

void solve(){
    cin >> n1 >> n2 >> K1 >> K2;
    memset(dp,-1,sizeof(dp));
    cout << get(0,0,K1,K2) << '\n';
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}
 