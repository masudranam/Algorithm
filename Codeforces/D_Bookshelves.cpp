#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<endl
#define aint(a) (a).begin(),(a).end()
#define sz(a) (int)(a.size())
#define int   long long int
#define endl '\n'
#define ar array
 
const int M = 1e9 + 7;
const int N = 39 + 1m0;

int dp[N][N];
int n, K, a[N], ans;

int get(int id, int cur){
    if(id == n){
        if(cur == K)return 1;
        else return 0;
    }
    if(dp[id][cur]!=-1)return dp[id][cur];
    int sum = 0;
    int ret = 0;
    for(int i = id; i < n; i++){
        sum += a[i];
        if((sum&ans) == ans){
            ret|=get(i+1,cur+1);
        }
    }
    return dp[id][cur] = ret;
}


void solve(){
    cin >> n >> K;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 60; i >= 0; i--){
        ans += (1ll<<i);
        memset(dp,-1,sizeof(dp));
        if(get(0,0) == 0)ans -= (1ll<<i);
    }
    
    cout << ans << endl;
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

