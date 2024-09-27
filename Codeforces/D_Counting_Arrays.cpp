#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 998244353;
const int N = 2e5 + 10;

int pw(int a, int b){
    int res = 1;
    a %= M;
    while(b){
        if(b&1) res = (res * a) % M;
        a = (a * a) % M;
        b >>= 1;
    }
    return res;
}
 
 bool prime(int x){
    for(int i = 2; i * i <= x; i++){
        if(x % i == 0)return false;
    }
    return true;
 }

void solve(){
    int n, m;
    cin >> n >> m;

    int res = 0;

    for(int i = 1; i <= n; i++){
        res = (res + pw(m, i)) % M;
    }
    
    int prod = 1, x = 1;
    for(int i = 1; i <= n; i++){
        if(x > m)continue;
        if(prime(i))x = x * i;

        prod = (prod  * ((m  / x) % M) ) % M;
        res = (res - prod) % M;
        res = (res + M) % M;
    }
    cout << res << '\n';
    
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}