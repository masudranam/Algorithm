#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<endl
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n; cin >> n;
    int k; cin >> k;
    vector<int> a(n);

    for(auto &x : a)cin >> x;

    int ans = 0, mn = 0, cur = 0;
    for(int i = 0; i < n; i++){
        cur += a[i];
        ans = max(ans, cur - mn);
        mn = min(cur, mn);
    }
     cur = ans;

    for(int i = 1; i <= k; i++){
        ans = (ans * ans) % M;
    }
    
    for(auto x : a) ans = (ans + x)%M;
    ans = (ans - cur) % M;

    ans = (ans + M) % M;
    cout << ans << endl;
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

