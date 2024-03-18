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
vector<int> ans;
int siz[N];


void dfs(int u, int p, int d){
    siz[u] = 1;
    for(auto v : g[u]){
        if(p == v)continue;
        dfs(v,u,d+1);
        siz[u] += siz[v];
    }
    if(u != 1 && sz(g[u]) == 0)ans.push_back(d);
}

void solve(){
    int n; cin >> n;
    for(int i = 0; i <= n; i++){
        g[i].clear();
    }

    for(int i = 2; i <= n; i++){
        int p; cin >> p;
        g[p].push_back(i);
    }

    ans.clear();

   dfs(1,0,0);

    sort(all(ans));

    if(sz(g[1]) >= 3 || ans.back() >= 5){
        cout << (n-1)/2<<endl;
        return;
    }

    if(sz(g[1]) == 2){
        if(siz[g[1][0]] >= 2 && siz[g[1][1]] >= 2){
            cout << (n-1)/2<<endl;
            return;
        }
        cout << max(1ll, (n-1)/2 - 1) << endl;
        return;
    }else{
        cout << max(0ll,(n-1)/2 - 1) << endl;
        return;        
    }

    cout<<(n-1)/2<<endl;


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