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

int dp[12][1010];
int n, m, c0, d0;

int a[110],b[110],c[110],d[110];

int get(int i, int cur){
    if(i == m){
        return (cur/c0)*d0;
    }
    int &ret = dp[i][cur];
    if(ret != -1)return ret;

    ret = get(i+1,cur);
    for(int j = 1; j <= min(a[i]/b[i],cur/c[i]); j++){
        ret = max(ret,get(i+1,cur-j*c[i]) + j*d[i]);
    }
    return ret;
}

void solve(){
    cin >> n >> m >> c0 >> d0;

    for(int i = 0; i < m; i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    memset(dp,-1,sizeof(dp));
    
    cout<<get(0,n)<<endl;
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

