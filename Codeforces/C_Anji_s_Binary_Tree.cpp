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

vector<pair<int,char>> g[N];
int n, ans;
string s;


void dfs(int u, int p,int d = 0){
    for(auto v: g[u]){
        if(v.first == p)continue;
        if(v.second == s[u])dfs(v.first,u,d);
        else dfs(v.first, u, d+1);
    }
  
    
    if(sz(g[u]) == 0)ans = min(ans,d);
}
void solve(){
    cin >> n;
    cin >> s;
    for(int i = 0; i <= n; i++)g[i].clear();

    for(int i = 0; i < n; i++){
        int l, r; cin >> l >> r;
        if(l)g[i].push_back({l-1,'L'});
        if(r)g[i].push_back({r-1,'R'});
    }
    ans = M;
    dfs(0,0);
    cout<<ans<<endl;
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

