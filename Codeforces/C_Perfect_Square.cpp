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
    int n; cin >> n;
    vector<string> s(n),t(n);

    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    int ans = 0;
    for(int i = 0; i < n/2; i++){
        for(int j = 0; j < n/2; j++){
            char a = s[i][j], b = s[j][n-i-1];
            char c = s[n-i-1][n-j-1],d = s[n-j-1][i];
            char e = max({a,b,c,d});
            int x = abs(a-e)+abs(b-e)+abs(c-e)+abs(d-e);
           // cout<<a<<b<<c<<d<<endl;
           ans += x;
        }
    }
    cout<<ans<<endl;
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

