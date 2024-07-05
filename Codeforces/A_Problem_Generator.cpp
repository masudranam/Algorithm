#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n, m; cin >> n >> m;
    string s; cin >> s;

    map<char,int> cnt;
    for(auto c : s)cnt[c]++;

    int ans = 0;
    for(char c = 'A'; c <= 'G'; c++){
        ans += max(0ll, m - cnt[c]);
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
