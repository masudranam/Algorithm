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

bool ok(vector<int> a, int n){
   for(int i = 1; i < n; i++){
      a[i+1] -= a[i];
      if(a[i+1] < 0)return false;
   }
   return a[n] == 0;
}

void solve(){
   int n; cin >> n;
   vector<int> a(n+2),p(n+2,-1),s(n+2,-1);

   for(int i = 1; i <= n; i++){
      cin >> a[i];
   }
   vector<int> b = a;
   reverse(all(b));

   if(ok(a,n) || ok(b,n)){
      cout<<"YES\n";return;
   }

   p[0] = 0;
   int cur = 0;
   for(int i = 1; i <= n; i++){
      cur = a[i]-cur;
      if(cur < 0)break;
      p[i] = cur;
   }
   s[n+1] = 0, cur = 0;
   for(int i = n; i >= 1; i--){
      cur = a[i] - cur;
      if(cur < 0)break;
      s[i] = cur;
   }

   for(int i = 1; i < n; i++){
      if(p[i-1] >= 0 && s[i+2] >= 0){
      int x = a[i+1] - p[i-1], y = a[i] - s[i+2];
      if(x == y && x >= 0){
         cout<<"YES\n";return;
      }

      }
   }
   cout<<"NO\n";

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

