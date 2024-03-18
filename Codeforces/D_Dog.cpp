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
int vis[N];
int n,q;

bool get(int u){
    
    if(u == n+1)return true;
    vis[u] = 1;
    for(auto v : g[u]){
        if(!vis[v] && get(v))return true;
    }
    return false;
}

void solve(){
   
    cin >> n >> q;
  

    for(int i = 0; i < q; i++){
        int l, r; cin >> l >> r;
        g[l].push_back(r+1);
        g[r+1].push_back(l);
    }

    if(get(1))cout <<"Yes\n";
    else cout <<"No\n";

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

