#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<endl
#define all(a) (a).begin(),(a).end()
#define sz(a) (int)(a.size())
#define int   long long int
#define endl '\n'
#define ar array
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

int dp[N];

int get(int x){
    if(x < 5)return x;
    int &ret = dp[x];
    if(ret != -1)return dp[x];
    ret = get(x-1)+1;
    for(int i = 2; i*i <= x; i++){
        if(x%i == 0)ret = min(ret,get(i)+get(x/i));
    }
    return ret;
}

void solve(){
    int n; cin >> n;
    memset(dp,-1,sizeof(dp));
    cout<<get(n)<<endl;
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

