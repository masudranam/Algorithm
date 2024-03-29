#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<endl
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int x, y, g;
    cin >> x >> y >> g;
    int x1 = (x + (M - g - 1)) / (M - g);
    int y1 = (y + g - 1) / g;
    int mx = max(x1,y1);
    int gcd = __gcd(x * mx, y * mx);

    cout << x*mx / gcd << "/" << y*mx / gcd << endl;
    
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

