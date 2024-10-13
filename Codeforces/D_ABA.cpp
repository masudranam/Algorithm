#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    string s; cin >> s;
    int n = s.size();
    vector<int> a(500, 0), b(500,0);

    for(int i = 0; i < n; i++){
        a[s[i]]++;
    }
    int res = 0;
    for(int i = 0; i < n; i++){
        a[s[i]]--;
        for(char c = 'A'; c <= 'Z'; c++){
            res += a[c] * b[c];
        }
        b[s[i]]++;
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
