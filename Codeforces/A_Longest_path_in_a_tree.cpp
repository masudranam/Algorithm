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

vector<int> g[N];

ar<int,2> dfs(int u, int p){
    ar<int,2> ret={-1,u};
    if(sz(g[u])==1)ret[0]=0;
    for(auto v: g[u]){
        if(v==p)continue;
        ar<int,2> x=dfs(v,u);
        if(x[0]==-1)continue;
        if(x[0]+1>ret[0])ret[0]=x[0]+1,ret[1]=x[1];
    }
    return ret;
}


void solve(){
    int n; cin >> n;
   

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

