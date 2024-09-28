#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<endl
#define all(a) (a).begin(),(a).end()
#define sz(a) (int)(a.size())
#define int   long long int
#define endl '\n'
#define ar array
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

vector<int> prefix_function (string s) {
   int n = (int) s.length();
   vector<int> pi (n);
   for (int i = 1; i < n; i++) {
      int j = pi[i - 1];
      while (j > 0 && s[i] != s[j])
         j = pi[j - 1];
      if (s[i] == s[j])
         j++;
      pi[i] = j;
   }
   return pi;
}

void solve(){
    string s; cin >> s;
    string t ; cin >> t;
    int x = sz(t);
    t = t + "$" + s;
    int ans = 0;
    vector<int> pi = prefix_function(t);
    for(int i = 0; i < sz(pi); i++){
        if(pi[i] >= x)ans++;
    }
    cout<<ans<<endl;
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

