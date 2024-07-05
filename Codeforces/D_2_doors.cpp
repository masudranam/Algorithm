#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n, q;
    cin >> n >> q;
    vector<int>a(n), allow(n,(1ll<<31)-1);
    vector<pair<int,int>> g[n];

    for(int i = 0; i < q; i++){
        int l, r, x;
        cin >> l >> r >> x;
        l--, r--;
        g[l].push_back({r,x});
        g[r].push_back({l,x});
        allow[l] &= x;
        allow[r] &= x;
        
        
    }

    for(int i = 0; i < n; i++){
         int res = 0;
         for(auto it : g[i]){
            res |= (~allow[it.first] & it.second);
            if(i == it.first) res = it.second;
         }
         allow[i] = res;
    }

    for(int i = 0; i < n; i++){
        cout << allow[i] << ' ';
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
