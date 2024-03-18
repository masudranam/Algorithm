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
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        for(int j = 2; j*j <= x; j++){
            int cnt = 0;
            while(x%j == 0)cnt++,x/=j;
            if(cnt)mp[j] = max(cnt,mp[j]);
        }
        if(x > 1){
            mp[x] = max(1ll,mp[x]);
        }
    }
    int ans = 0;
    for(auto it: mp){
        ans += it.second;
    }
    if(ans&1)cout<<"Alice\n";
    else cout<<"Bob\n";

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

