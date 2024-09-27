#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(auto &x : a) cin >> x;

    pair<int,int> res{M, 0};

    for(int i = 1; i <= 100; i++){
        int cur = 0;
        for(int j = 0; j < n; j++){
            cur += max(0ll, abs(a[j] - i) - 1);
        }
        res = min(res,{cur, i});
    }
    cout << res.second << ' ' << res.first << '\n';
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