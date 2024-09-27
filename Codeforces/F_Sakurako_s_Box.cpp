#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
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

void solve(){
    int n; cin >> n;
    vector<int> a(n), s(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
        s[i] = a[i];
    }
    for(int i = n - 2; i >= 0; i--){
        s[i] = s[i + 1] + a[i];
    }

    int res = 0;
    for(int i = 0; i + 1 < n; i++){
        res += ((a[i] % M) * (s[i + 1] % M));
        res = res % M;
    }
    n = (n * (n - 1) / 2) % M;
    int inv = pw(n, M - 2);
    res = (res * inv) % M;
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
