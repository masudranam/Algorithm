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
    int m, w;
    cin >> w >> m;
    if(w == 2){
        cout<<"YES\n";
        return;
    }
    vector<int> a{m};
    int pw = 1;
    for(int pw = 1; ;pw *= w){
        a.push_back(pw);
        if(pw > m)break;
    }
    map<int,int>mp;

    int n = sz(a); 
    for(int i = 1; i < (1<<n); i++){
        int cur = 0;
        for(int mask = 0; mask < n; mask++){
            if(i &(1<<mask))cur += a[mask];
        }
        if(mp[cur]){
            cout<<"YES\n";
            return;
        }
        mp[cur]++;
    }
    cout<<"NO\n";



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

