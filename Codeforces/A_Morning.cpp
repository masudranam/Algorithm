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
    s = "1"+s;
    int ans = 0;

    for(int i = 1; i < sz(s); i++){
        if(s[i] == s[i-1])continue;
        
        if(s[i-1] == '0')ans += abs(10-(s[i]-'0'));
        else if(s[i] == '0')ans+=abs(10-(s[i-1]-'0'));
        else ans += abs(s[i]-s[i-1]);
    }
    cout<<ans+4<<endl;
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

