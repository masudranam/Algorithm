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
   map<string,vector<int>>mp;
   for(int i = 1; i < 600000; i++){
    string s = to_string(i*i);
    sort(all(s));
    mp[s].push_back(i*i);
   }
    
    vector<int>g[20];
    int mx = 0;
    for(auto it : mp){
        mx = max(mx,sz(it.second));
        if(sz(g[sz(it.first)]) < sz(it.second)){
            g[sz(it.first)] = it.second;
        }
    }

    cout << mx << endl;

 
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

