#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<endl

const int M = 1e9 + 7;
const int N = 2e5 + 10;


void solve(){

    unsigned long long a, b, c, d;
    cin >> a >> b >> c >> d;
    unsigned long long gab = __gcd(a,b), gcd = __gcd(c,d);
    a /= gab, b /= gab, c /= gcd, d /= gcd;
    if(a*d == b*c)cout << "Equal\n";
    else cout << "Not Equal\n";

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

