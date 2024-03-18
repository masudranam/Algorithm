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
   if(s[0] == '0'){
      cout<<-1<<endl;
      return;
   }

   for(int i = 1; i < sz(s); i++){
      if(s[i] == '0')continue;
      string m = s.substr(0,i), n = s.substr(i);
      int m1 = stoi(m), n1 = stoi(n);
      if(m1 < n1){
         cout<<m1<<' '<<n1<<endl;
         return;
      }
   }
   cout<<-1<<endl;
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

