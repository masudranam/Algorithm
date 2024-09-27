#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

int pw(int a, int b){
    int res = 1;
    while(b){
        if(b&1)res = (res * a) % M;
        a = (a * a) % M;
        b >>= 1;
    }
    return res;
}

void solve(){
    int l, r, k;
    cin >> l >> r >> k;
   
    int res = 0;
    if(k > 9){
        cout << 0 << '\n'; return;
    }
    res = pw(9/k + 1,r) - pw(9/k + 1, l);
    res = (res%M + M) % M;
    cout << res << '\n';
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
