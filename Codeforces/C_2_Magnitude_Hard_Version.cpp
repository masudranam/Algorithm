#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
<<<<<<< HEAD
 
=======

>>>>>>> c4b296f099f991f3e9d36d132405de9dfa1105d9
const int M = 998244353;
const int N = 2e5 + 10;

void solve(){
    int n; cin >> n;
<<<<<<< HEAD
    
    map<int,int> dp;
    dp[0] = 1;

    for(int i = 0; i < n; i++){
        int a; cin >> a;
        map<int,int> ndp;
        swap(ndp,dp);
        for(auto [x, y] : ndp){
            dp[a + x] = (dp[a + x] + y) % M;
            dp[abs(a + x)] = (dp[abs(a + x)] + y) % M;
        }
        auto it = dp.begin();
        it++;
        while(it != dp.end() && next(it) != dp.end()){
            it = dp.erase(it);
        }
    }
    cout << dp.rbegin()->first << '\n';
}


=======
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

>>>>>>> c4b296f099f991f3e9d36d132405de9dfa1105d9
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
<<<<<<< HEAD
=======

>>>>>>> c4b296f099f991f3e9d36d132405de9dfa1105d9
