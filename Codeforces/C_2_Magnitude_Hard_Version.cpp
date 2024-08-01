#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 998244353;
const int N = 2e5 + 10;

void solve(){
    int n; cin >> n;
    vector<int> p(n+1,1), a(n);
    for(int i = 1; i <= n; i++){
        p[i] = (p[i-1] * 2) % M;
    }

    int mn = 0, ans = 0, pos = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        pos += a[i];
        mn = min(mn, pos);
    }
    pos = 0;
    if(mn == 0){
        cout << p[n] << '\n';return;
    }
    int cur = 0;

    for(int i = 0; i < n; i++){
        cur += a[i];
        if(cur >= 0)pos++;
        if(cur == mn){
            ans = (ans + p[n - i - 1 + pos]) % M;
        }
    }
    cout << ans << '\n';
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

