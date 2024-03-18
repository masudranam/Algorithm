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
int dp[5001][5001];
int n,K,a[5001];

int get(int i, int k){
    cout<<i<<"->"<<k<<endl;
    if(i >= n){return 0;}
    int ret = -M;
     if(a[i] < 0 && k < K)ret = get(i+1,k+1);
     ret = max(ret,get(i+1,k)+a[i]);
     
     ret = max(ret,a[i]);
     //cout<<i<<' '<<k<<' '<<ret<<endl;
     return ret;
}


void solve(){
    cin >> n >> K;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    memset(dp,-1,sizeof(dp));
    int ans = -M;
    get(2,0);
    for(int i = 0; i < n; i++){
        //ans = max(ans,get(i,0));
    }

    cout<<ans<<endl;
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

