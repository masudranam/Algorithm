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
string s; cin >> s;

vector<int> ans(n),cnt(26,0);

for(int i = n-1; i >= 0; i--){
   int mx = 0;
   for(int c = 0; c < (s[i]-'a'); c++){
      mx = max(cnt[c],mx);
   }
   ans[i] = mx + 1;
   //cout << i <<' ' << mx << endl;
   cnt[s[i]-'a'] = max(cnt[s[i]-'a'],mx+1);
}
int mx = 0;
for(int i = 0; i < 26; i++){
   mx = max(mx, cnt[i]);
}
cout << mx <<endl;
for(int i = 0; i < n; i++){
   cout << ans[i] <<' ';
}
cout << endl;

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

