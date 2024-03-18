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
const int N = 5e5 + 10;

void solve(){
    int n;
    cin >> n;
    vector<int> g[2*n+10];
    vector<int> a(n),b(n),ca(n),cb(n);
    
    for(auto &x: a) cin >> x;
     for(auto &x: ca)cin >>x;
     for(auto &x: b) cin >> x;
     for(auto &x: cb)cin >> x;

    vector<int> vis(2*n+2);
    for(int i = 0; i < n; i++){
        vis[cb[i]] = 1;
    }

    for(int i = 0; i < n; i++){
        if(vis[ca[i]]){
            g[ca[i]].push_back(a[i]);
        }
        g[cb[i]].push_back(b[i]);
    }
    for(int i = 0; i <= 2*n+2; i++)
        sort(all(g[i]));

    vector<int> ans(n);

    int mx = M*M;
    for(int i = n-1; i >= 0; i--){
        int x = ca[i];
        if(!vis[x]){
            ans[i] = a[i];
            mx = min(mx,ans[i]);
            continue;
        }

        while(sz(g[x])  && g[x].back() > mx){
            g[x].pop_back();
        }
        if(sz(g[x]) == 0){
            cout<<"No\n";return;
        }
        ans[i] = g[x].back();
        g[x].pop_back();
        mx = min(ans[i],mx);
    }

    for(int i = 1; i < n; i++){
        if(ans[i] < ans[i-1]){
            cout<<"No\n"; return;
        }
    }

    cout<<"Yes\n";
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

