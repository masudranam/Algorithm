#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n; cin >> n;
    map<int,int> mp;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        mp[x]++;
    }
    vector<int> a;
    for(auto it : mp){
        if(it.first == 0)continue;
        a.push_back(it.second);
    }
    if(a.size() == 0){
        cout << n * (n - 1) / 2 << '\n';
    }else{
        sort(a.begin(), a.end());
        a.back() += mp[0];
        int res = 0;
        for(int i = 0; i < a.size(); i++){
            res += a[i] * (a[i] - 1) / 2;
        }
        cout << res << '\n';
    }
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
