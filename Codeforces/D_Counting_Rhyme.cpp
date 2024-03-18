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
const int N = 2e6 + 10;

int ache[N];
vector<int> g[N],d[N];

void solve(){
    int n; cin >> n;

    for(int i = 0; i <= n; i++){
        g[i].clear(); d[i].clear(); ache[i] = 0;
    }

    for(int i = 2; i <= n; i++){
        for(int j = i; j <= n; j+= i){
            d[j].push_back(i);
        }
    }

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        ache[x] = 1;
        for(auto v : d[x]){
            g[v].push_back(i);
        }
    }    

   
    if(ache[1]){
        cout << 0 << endl;
        return;
    }

    vector<int> vis(n),vis1(n+1);
    int ans = n*(n-1)/2;

    for(int i = 2; i <= n; i++){
        if(!ache[i] || vis1[i])continue;
        int tot = sz(g[i]), cnt = 0;
        for(auto v : g[i]){
            cnt += vis[v];
            vis[v] = 1;
        }
        tot -= cnt;
        ans -= tot*(tot-1)/2;
        ans -= tot*cnt;
        for(int j = i; j <= n; j += i){
            vis1[j] = 1;
        }
    }
        cout << ans << endl;
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

