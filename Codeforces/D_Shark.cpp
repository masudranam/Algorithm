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
   vector<int> p,siz;
   DSU(int n){
      p.assign(n+1,0);
      siz.assign(n+1,1);
      iota(all(p),0);  
   }

   int get(int x){
      if(p[x] == x) return x;
      return p[x] = get(p[x]);
   }

   void Merge(int a, int b){
      a  = get(a), b = get(b);
      if(siz[a] < siz[b])swap(a,b);
      siz[a] += siz[b];
      p[b] = a;
   }
};

void solve(){
    int n; cin >> n;
    vector<pair<int,int>> p(n);

    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        p[i-1] = {x,i};
    }
    sort(all(p));

    ar<int,2> ans{1,-p[0].first-1};
    vector<int> vis(n+3);
    multiset<int> st;

    DSU dsu(n+5);
    
    for(int i = 0; i < n; i++){
        int id = p[i].second;
        int x = p[i].first;

        if(vis[id-1]){
            dsu.Merge(id-1,id);
            int siz = dsu.siz[dsu.get(id)];
            st.erase(st.find(siz-1));
            st.insert(siz);
            vis[id] = 1;
        }else if(vis[id+1]){
             dsu.Merge(id+1,id);
            int siz = dsu.siz[dsu.get(id)];
            st.erase(st.find(siz-1));
            st.insert(siz);
            vis[id] = 1;
        }else{
            vis[p[i].second] = 1;
            st.insert(1);
        }
      
        if(*st.begin() == *st.rbegin()){
            ans = max(ans, {sz(st),-p[i].first-1});
        }
    }

    cout << -ans[1] << endl;

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

