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

void solve(){
 string s; cin >> s;
  for(char c = 'a'; c <= 'h'; c++){
    if(c == s[0])continue;
    string t;
    t += c;
    t += s[1];
    cout<<t<<endl;
  }

  for(char d = '1'; d <= '8'; d++){
    if(d == s[1])continue;
    string t; t += s[0];
    t += d;
    cout<<t<<endl;
  }
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

