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
int vis[N],col[N];

bool Bipart(int u,int c=0){
 vis[u]=1;
 col[u]=c;
 for(auto v:g[u]){
    if(!vis[v]){
        if(!Bipart(v,c^1))return false;
    }else if(col[v]==col[u])return false;
 }
 return true;
 }

void solve(){
    int n;
    
    while(true){
        cin >> n;
        if(n==0)break;
        for(int i = 0; i <= n; i++){
            g[i].clear(),vis[i] = col[i] = 0;
        }
        cin >> n;
        for(int i = 0; i < n; i++){
            int u, v; cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if(isBipart(1))cout<<"BICOLORABLE.\n";
        else cout<<"NOT BICOLORABLE.\n";
    }

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

