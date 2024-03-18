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
    int n, k; 
    cin >> n >> k;

    vector<int> p(11);
    p[0] = 1;
    for(int i = 1; i <= 10; i++){
        p[i] = p[i-1]*10;
    }

    vector<int> a(n);
    for(auto &x : a) cin >> x;

    map<int,int> mp[11];

    signed int ans = 0;

    for(int i = 0; i < n; i++){
        int len = sz(to_string(a[i]));
        int need = (k - a[i]%k) % k;

        if(mp[len].find(need) != mp[len].end()){
            ans += mp[len][need];
        }
        for(int j = 1; j <= 10; j++){
            mp[j][(a[i]*p[j])%k]++;
        }
    }
    for(int i = 1; i <= 10; i++){
        mp[i].clear();
    }

     for(int i = n-1; i >= 0; i--){
        int len = sz(to_string(a[i]));
        int need = (k - a[i]%k) % k;

        if(mp[len].find(need) != mp[len].end()){
            ans += mp[len][need];
        }
        for(int j = 1; j <= 10; j++){
            mp[j][(a[i]*p[j])%k]++;
        }
    }

    cout << ans << endl;

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;  // cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

