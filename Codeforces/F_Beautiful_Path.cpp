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
const double eps = 1e-9;

vector<ar<int,3>>g[N];
double dp[N];
int n, m;

bool ok(double w){
    for(int i = 0; i <= n; i++){
        dp[ i ] = -1.0*M;
    }
    dp[1] = 0;

    for(int u = 1; u <= n; u++){
        for(ar<int,3> v: g[u]){
            dp[u] = max(dp[u],dp[v[0]]+(1.0*v[1]-w*v[2]));
        }
    }
    return (dp[n] >= 0.0);
}

void solve(){
    cin >> n >> m;

    for(int i = 1; i <= m; i++){
        int u, v, a, b;
        cin >> u >> v >> a >> b;
        g[v].push_back({u,a,b});
    }
    double l = 0, r = M;
    while(r-l > eps){
        double mid = (l+r)/2.0;
        if(ok(mid))l = mid;
        else r = mid;
    }
    cout<<fixed<<setprecision(16)<<l+eps<<endl;
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

