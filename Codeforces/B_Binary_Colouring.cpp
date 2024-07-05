#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int x; cin >> x;
    vector<int> a(32);

    for(int i = 0; i < 32; i++){
        a[i] = (x>>i)&1;
        if(i && a[i] != 0 && a[i-1] != 0){
            a[i] = 0;
            x += (1ll<<i)/2;
            a[i-1] = -1;
        }
    }
    cout << 32 << '\n';
    for(int i = 0; i < 32; i++){
        cout << a[i] << ' ';
    }
    cout << '\n';
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
