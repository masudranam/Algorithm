#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
#define ld  long double
const int M = 1e9 + 7;
const int N = 2e5 + 10;

ld d(int a, int b, int c, int d){
    ld res = (a - c) * (a - c) + (b - d) * (b - d);
    return sqrtl(res);
}

void solve(){
    int n; cin >> n;
    int x[n + 1], y[n + 1];
    x[0] = y[0] = 0;

    for(int i = 1; i <= n; i++){
        cin >> x[i] >> y[i];
    }
    ld  res = 0;
    for(int i = 1; i <= n; i++){
        res += d(x[i-1], y[i - 1], x[i], y[i]);
    }
    res += d(x[0], y[0], x[n], y[n]);
    cout <<fixed << setprecision(20) << res << '\n';

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1; 
  // cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}
