#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int res = 0;
    for(int i = 2; i < n; i++){
        if(s[i] == '#' && s[i] == s[i - 2] && s[i] != s[i - 1])res++;
    }
    cout << res << '\n';
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1; 
//   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}
