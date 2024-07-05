#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int x, y;
    cin >> x >> y;
    x = x^y;

    int ans = 0, cur = 0;

    for(int i = 0; i < 40; i++){
        if((x&(1ll<<i))){
            cout << (1ll<<i) << '\n';;
            return;
        }
    }
    cout << 0 << '\n';
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
