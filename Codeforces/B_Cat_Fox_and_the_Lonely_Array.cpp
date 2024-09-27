#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n; cin >> n;

    vector<int> g[21];
    for(int i = 0; i < 21; i++)g[i].push_back(-1);

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        for(int bit = 0; bit < 21; bit++){
            if((x>>bit)&1)g[bit].push_back(i);
        }
    }
    for(int i = 0; i < 21; i++)g[i].push_back(n);

    int ans = 0;
    for(int i = 0; i < 21; i++){
        if(g[i].size() <= 2)continue;
        for(int j = 1; j < g[i].size(); j++){
            ans = max(ans, g[i][j] - g[i][j-1]);
        }
    }
    cout << max(ans, 1ll) << '\n';
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