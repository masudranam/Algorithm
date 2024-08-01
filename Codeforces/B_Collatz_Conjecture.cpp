#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int x, y, k;
    cin >> x >> y >> k;

    while(k > 0){
        int t = ((x/y)+1)*y;
        t = min(k, t - x);
        k -= t;
        x += t;
        
        while(x % y == 0)x /= y;
        if(x == 1){
            int y1 = y - 1;
            k -=  (k/y1)*y1;
        }
    }
    cout << x << '\n';
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

