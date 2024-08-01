#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int x1, y1;
    int x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    string ans = "NO\n";
    if(min(x1,x2) <= min(y1,y2) && max(x1,x2) <= max(y1,y2)){
        ans = "YES\n";
    }
    if(min(y1,y2) <= min(x1,x2) && max(y1,y2) <= max(x1,x2)){
        ans = "YES\n";
    }
    cout << ans ;
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

