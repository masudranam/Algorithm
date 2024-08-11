#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

int M = 1e9 + 7;
const int N = 2e5 + 10;
int n, k, sum;

int dp[101][32][2];

int get(int i, int s, int ok){
    if(i == n){
        return s == sum && ok;
    }
    int &ret = dp[i][s][ok];
    if(ret != -1) return ret;
    ret = 0;
    for(int j = 0; j < k; j++){
        ret = (ret + get(i+1, (j+s)%k, ok | ((2*j) % k == sum))) % M;
    }
    return ret;
}

void solve(){
    cin >> n >> k >> M;
    int res = 0;
    for(sum = 0; sum < k; sum++){
        memset(dp,-1,sizeof(dp));
        res = (res + get(0,0,0)) % M;
    }
    cout << res << '\n';
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