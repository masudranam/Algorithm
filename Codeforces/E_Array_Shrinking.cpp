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

void solve(){
    int n;
    cin >> n;

    int a[n+1];
    int tp[n+1][n+1];

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    memset(tp,-1,sizeof(tp));

    for(int len = 1; len <= n; len++){
        for(int j = len; j <= n; j++){
            int i = j - len + 1;
            if(len == 1)tp[i][j] = a[i];
            for(int k = i; k < j; k++){
                if(tp[i][k] == -1)continue; 
                if(tp[i][k] == tp[k+1][j]){
                    tp[i][j] = tp[i][k]+1;
                }   
            }
        }
    }
    vector<int> dp(n+1,M);

    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            if(tp[j][i] != -1){
                dp[i] = min(dp[i],dp[j-1]+1);
            }
        }
    }
    cout<<dp[n]<<endl;
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

