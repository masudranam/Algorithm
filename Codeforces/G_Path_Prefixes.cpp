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

vector<ar<int,3>> g[N];
vector<int> path,ans;
int sum;

void dfs(int u, int p){
    for(auto v : g[u]){
        if(v[0] == p)continue;
        if(path.empty())path.push_back(v[2]);
        else path.push_back(path.back()+v[2]);
        sum += v[1];
        auto it = upper_bound(all(path),sum)-path.begin();
        ans[v[0]] = it;
        dfs(v[0],u);
        sum -= v[1];
        path.pop_back();
    }
}

void solve(){
    int n;
    cin >> n;
    ans.assign(n+1,0);
    for(int i = 0; i <= n; i++){
        g[i].clear();
    }

    for(int i = 2; i <= n; i++){
        int p, a, b;
        cin >> p >> a >> b;
        g[p].push_back({i,a,b});
    }
    
    sum = 0; path.clear();
    dfs(1,0);

    for(int i = 2; i <= n; i++){
        cout << ans[i] << ' ';
    }
    cout << endl;
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

