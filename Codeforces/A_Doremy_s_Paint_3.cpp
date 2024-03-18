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
    map<int,int> mp;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        mp[x]++;
    }
    if(sz(mp)>2){
        cout<<"No\n";return;
    }
    if(sz(mp) == 1){
        cout<<"Yes\n";return;
    }
    vector<int> v;
    for(auto x: mp){
        v.push_back(x.second);
    }
    if(abs(v[0]-v[1])>1){
        cout<<"No\n";return;
    }
    cout<<"Yes\n";
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

