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

int n, k, cost[10][10],dp[10][1<<10];

int get(int i, int mask,int cur){
    if(mask == 1){
        if(cost[i][0] + cur == k)return 1;
        return 0;
    }

   // if(dp[i][mask] != -1) return dp[i][mask];
    int res = 0;

    for(int j = 1; j < n; j++){
        if(i == j)continue;
        if(mask&(1<<j)){
            res += get(j,mask - (1<<j),cur + cost[i][j]);
        }
    }
    return  res;
}

void solve(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> cost[i][j];
        }
    }

    memset(dp,-1,sizeof(dp));

    cout << get(0,(1<<n)-1,0) << endl;
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

