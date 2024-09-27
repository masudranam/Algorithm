#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int x, y; cin >> x >> y;
    int k; cin >> k;
    if(k == 1){
        cout << x << ' ' << y << '\n';
        return;
    }

    int x0 = 0, y0 = 0;

    for(int i = 0, s = N; i + 1 < k; i++){
        cout << s <<' ' << s <<'\n';
        x0 += s, y0 += s;
        s++;
    }
    cout << x*k - x0 <<' ' << y*k - y0 <<'\n';
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