#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n; cin >> n;
    int x; cin >> x;
    map<int,int> vis;

    int res = 0;

    for(int i = 0; i < n; i++){
        int a; cin >> a;
        

        if(a == 1 || (x % a))continue;
        if(vis.find(x/a) != vis.end()){
            res++;
            vis.clear();
            vis[a] = 1;
            continue;
        }
     
        
        map<int,int> mp = vis;
        vis[1] = 1;
        for(auto it : vis){
             mp[it.first * a] = 1;
        }
        vis = mp;
}
    cout << (res + 1) << '\n';
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