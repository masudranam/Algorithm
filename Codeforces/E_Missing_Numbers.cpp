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
const int N = 2e5 + 100;

vector<pair<int,int>> edges[N];

vector<int> g[N];
int vis[N];

vector<int> cur,ans;
int n,ok;

void dfs(int u){
    if(ok || vis[u])return;
    cur.push_back(u);
    vis[u] = 1;
    if(!ok && sz(cur) == n){
        ans = cur;
        ok = 1;
    }

   for(auto v: g[u]){
    if(!vis[v])
      dfs(v);
   }
cur.pop_back();
}


void solve(){
   cin >> n;

   for(int u = 1; u < N; u++){
      for(int v = 1; v < N && v*(2*u+v) < N; v++){
         edges[v*(2*u+v)].push_back({u,u+v});
      }
   }

   vector<int> a(n/2);
   for(auto &x : a) cin >> x;

   for(int i = 0; i < n/2; i++){
      for(auto it : edges[a[i]]){
         g[it.first].push_back(it.second);
      }
   }

   for(int i = 0; i < n/2; i++){
    sort(all(edges[a[i]]));
   }


   for(int i = 1; i < n/2; i++){
    int cnt = 50;
       for(auto u : edges[a[i-1]]){
        pair<int,int> p{u.second+1,0};
        auto it = lower_bound(all(edges[a[i]]),p)-edges[a[i]].begin();
        for(int j = 0; j < sz(edges[a[i]]); j++){
            if(u.second < edges[a[i]][j].first)
            g[u.second].push_back(edges[a[i]][j].first);
        }
       }
   }  


    for(auto it : edges[a[0]]){
        if(ok)break;
        if(!vis[it.first])
        dfs(it.first);
    }

   if(sz(ans) < n){
    cout<<"No\n";
    return;
   }

    ans.insert(ans.begin(),0);
    cout<<"Yes\n";
    for(int i = 1; i < sz(ans); i++){
        cout<<ans[i]*ans[i] - ans[i-1]*ans[i-1]<<' ';
    }
    cout<<endl;
    
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

 