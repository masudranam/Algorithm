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

const int sq = 450;

map<int,int> mp[sq][sq], sm[sq][sq];

void solve(){
  int n, q;
  cin >> n >> q;
  int a[n+1];

  for(int i = 1; i <= n; i++){
   cin >> a[i];
  }

  for(int k = 1; k < sq; k++){
   for(int s = 1; s <= k; s++){
      for(int i = s; i <= n; i+= k){
         mp[k][s][i] = (mp[k][s][i-k] + ((i-s+k)/k)*a[i]);
         sm[k][s][i] = (sm[k][s][i-k] + a[i]);
      }
   }
  }

  while(q--){
   int s, d, k;
   cin >> s >> d >> k;
   int ans = 0;
   if(d >=sq){
      for(int i = 1; i <= k; i++){
         ans += k*(a[s+d*(k-1)]);
      }
      cout << ans << endl;
   }else{
      int ans = mp[d][s][s+d*(k-1)] - mp[d][s][]
   }
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

