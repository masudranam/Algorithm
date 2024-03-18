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

set<int> g[N];
int p[N],d[N];

void dfs(int u, int pr, int di){
    p[u] = pr;
    d[u] = di;
    for(auto v: g[u]){
        if(pr != v){
            dfs(v,u,di+1);
        }
    }
}

void solve(){
    int n; cin >> n;
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
    }

    set<ar<int,2>> st;
    dfs(1,0,0);
    for(int i = 1; i <= n; i++){
        if(d[i] > 2){
            st.insert({-d[i],i});
        }
    }
    int ans = 0;

    while(sz(st)){
        ans++;
        int u = (*st.begin())[1];
        u = p[u];
        if(st.find({-d[u],u}) != st.end()){
            st.erase({-d[u],u});
        }
        
        vector<int> vec;
        vec.push_back(u);
        for(auto v: g[u]){
            vec.push_back(v);
            auto it = st.find({-d[v],v});
            if(it != st.end()){
                st.erase(it);
            }
        }
        for(auto v: vec)g[v].erase(u),g[u].erase(v);
    }
    cout << ans << endl;
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