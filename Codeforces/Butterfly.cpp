#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int a[3];
    for(auto &it : a) cin >> it;
    bool ok = 1;
    for(int i = 0; i < 3; i++){
        int s = 0;
        for(int j = 0; j < 3; j++){
            if(i == j)s -= a[j];
            else s += a[j];
        }
        ok &= (s >= 0);
    }
    if(ok) cout << "YES\n";
    else cout << "NO\n";
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1; 
   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}
