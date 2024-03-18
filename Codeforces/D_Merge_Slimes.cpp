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
    map<int,int>mp;

    for(int i = 0;i < n; i++){
        int c, s;
        cin >> s >> c;
        mp[s] += c;
       
    }
    int ans = 0;

    while(sz(mp)){
        auto it = mp.begin();
        mp.erase(mp.begin());
        ans += (it->second%2);
        
        if(it->second > 1)mp[2*it->first] += it->second/2;
    }

    cout<<ans<<endl;
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

