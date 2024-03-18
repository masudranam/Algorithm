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

struct DSU{
   vector<int> p,siz,even;
   DSU(int n){
      p.assign(n+1,0);
      siz.assign(n+1,1);
      even.assign(n+1,0);
      iota(all(p),0);  
   }

   int get(int x){
      if(p[x] == x) return x;
      return p[x] = get(p[x]);
   }

   bool Merge(int a, int b){
      a  = get(a), b = get(b);
      if(a == b) return true;
      if(siz[a] < siz[b])swap(a,b);
      siz[a] += siz[b];
      even[a] += even[b];
      p[b] = a;
      return false;
   }
};

struct Edge{
    int u, v, w;
};

void solve(){
    int n, m;
    cin >> n >> m;

    Edge e[m];
  
    vector<DSU>dsu(31,n);

    for(int i = 0; i < m; i++){
        cin >> e[i].u >> e[i].v >> e[i].w;
        e[i].u--, e[i].v--;
        for(int j = 0; j < 30; j++){
            if(e[i].w&(1<<j)){
                dsu[j].Merge(e[i].u,e[i].v);
            }
        }
    }
    vector<int> even(n);

    for(int j = 0; j < 30; j++){
        vector<int>vis(n);
        for(int i = 0; i < m; i++){
            if(e[i].w%2 == 0){
                vis[dsu[j].get(e[i].u)] = 1;
                vis[dsu[j].get(e[i].v)] = 1;
            }
        }
        for(int i = 0; i < n; i++){
            if(vis[dsu[j].get(i)])even[i] = 1;
        }
    }
    int q; cin >> q;
    vector<int> ans(q,2);

    for(int i = 0; i < q; i++){
        int u, v; cin >> u >> v;
        u--, v--;
        for(int j = 0; j < 30; j++){
             int u1 = dsu[j].get(u);
             int v1 = dsu[j].get(v);
            if(u1 == v1){
                ans[i] = 0;
                break;
            }
            if(even[u]){
            ans[i] = min(ans[i],1ll);
        }
        }
        
    }


    for(int i = 0; i < q; i++){
        cout << ans[i] << endl;
    }
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