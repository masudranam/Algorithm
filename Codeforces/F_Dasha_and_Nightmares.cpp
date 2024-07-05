#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n; cin >> n;
    unordered_map<int,int> cnt[26];
    long long int ans = 0;

    for(int i = 0; i < n; i++){
        string s; cin >> s;
        vector<int> f(26);
        int mask = 0;
        for(auto c : s){
            f[c - 'a']++;
            mask ^= (1<<(c - 'a'));
        }
        int mask1 = (1<<26)-1 ^ mask;

        for(int j = 0; j < 26; j++){
            if(f[j] == 0){
                ans += cnt[j][mask1^(1<<j)];
                cnt[j][mask]++;
            }
        }
    }

    cout << ans << '\n';
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
