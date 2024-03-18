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
const int N = 3e5 + 10;

vector<int> g[N];

void dfs(int u){
    cout << u <<' ';
    for(auto v : g[u]){
        dfs(v);
    }
}

void solve(){
    int n; cin >> n;
    int root = 1;

    for(int i = 1; i <= n; i++){
        int x; cin >> x;
   
        if(x == -1){
            root = i;
        }else{
            g[x].push_back(i);
        }
    }

  
    dfs(root);

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

