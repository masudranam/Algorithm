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
    int n; 
    cin >> n;
    string s; cin >> s;

    map<ar<int,2>,int>mp;
    int x = 1, y = 1;
    ar<int,3> ans{-1,-1,M};
    mp[{x,y}] = -1;
    for(int i = 0; i < n; i++){
        x += s[i]=='R';
        x -= s[i]=='L';
        y += s[i]=='U';
        y -= s[i]=='D';
        if(mp.find({x,y}) != mp.end()){
            if(i-mp[{x,y}] < ans[2]){
                ans[0] = mp[{x,y}]+1;
                ans[1] = i;
                ans[2] = i-mp[{x,y}];
            }
        }
        mp[{x,y}] = i;
    }
    if(ans[0] == -1)cout << -1 << endl;
    else cout << ans[0] + 1 <<' ' << ans[1] + 1 << endl;

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

