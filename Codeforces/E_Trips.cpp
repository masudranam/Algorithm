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
int deg[N],n,m,k;
 set<ar<int,2>>st;
vector<ar<int,2>>edge(N);

void del(int u, int d){
    
    if(d < k){
        st.erase(st.begin());
        vector<int> tmp;
        for(auto v: g[u]){
            tmp.push_back(v);
                st.erase({deg[v],v});
                deg[v]--;
                st.insert({deg[v],v});
        }
        for(auto x: tmp){
            g[x].erase(u);
            g[u].erase(x);
        }
    }
}

void solve(){
  
    cin >> n >> m >> k;
   
    for(int i = 0; i < m; i++){
        int u, v; 
        cin >> u >> v, u--, v--;
        edge[i] = {u,v};
        g[u].insert(v);
        g[v].insert(u);
        deg[u]++,deg[v]++;
    }

    for(int i = 0; i < n; i++){
        st.insert({deg[i],i});
    }
    vector<int> ans(m);

    for(int i = m-1; i >= 0; i--){

        while(sz(st)){
            ar<int,2> t = *st.begin();
            if(t[0] < k)del(t[1],t[0]);
            else break;
        }
        
        ans[i] = sz(st);

        int u = edge[i][0], v = edge[i][1];
        if(g[u].find(v) != g[u].end()){
            st.erase({deg[u],u});
            st.erase({deg[v],v});
            deg[u]--, deg[v]--;
            st.insert({deg[u],u});
            st.insert({deg[v],v});
            g[u].erase(v);
            g[v].erase(u);
        }
    }

    for(int i = 0; i < m; i++){
        cout<<ans[i]<<'\n';
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

