#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n);

    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;

    auto ok = [&](int res){
        map<int,int> cnt;
        for(auto x : a) cnt[x&res]++;
        for(auto x : b) cnt[~x&res]--;
        bool f = true;
        for(auto y : cnt){
            f &= (y.second == 0);
        }
        return f;
    };

    int ans = 0;

    for(int i = 30; i >= 0; i--){
        if(ok(ans | (1<<i))){
            ans |= (1 << i);
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