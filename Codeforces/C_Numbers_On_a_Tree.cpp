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

    int h; cin >> h;
    string s; cin >> s;
    int n = sz(s);
    int cur = 1;
    for(int i = 0; i < n; i++){
        if(s[i] == 'L')cur *= 2;
        else cur = (cur*2 + 1);
    }
     //debug(cur);
    int tot = (1ll << (h+1))-1;
   // debug(tot);
    cout << tot-cur+1 << endl;

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

