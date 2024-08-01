#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n; cin >> n;

    map<int,int> res, cur, nxt;

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        nxt.clear();
        cur[x]++;
        for(auto it : cur){
            int g = __gcd(x,it.first);
            nxt[g] += it.second;
            res[g] += it.second;
        }
        cur = nxt;
    }
    int q; cin >> q;
    for(int i = 0; i < q; i++){
        int x; cin >> x;
        cout << res[x] << '\n';
    }
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

