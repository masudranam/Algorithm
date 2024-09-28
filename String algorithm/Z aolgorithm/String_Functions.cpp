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

vector<int> z_function (string s) {
   int n = (int) s.length();
   vector<int> z (n);
   int l = 0, r = 0;
   for (int i = 1; i < n; ++i) {
      if (i <= r)
         z[i] = min (r - i + 1, z[i - l]);
      while (i + z[i] < n && s[z[i]] == s[i + z[i]])
         ++z[i];
      if (i + z[i] - 1 > r)
         l = i, r = i + z[i] - 1;
   }
   return z;
}

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
    vector<int> z = z_function(s), pi = prefix_function(s);
    print(z);print(pi);
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

