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
const int N = 2e6 + 10;


void solve(){
   int n; cin >> n;
   vector<int> a;
   int ans = 0;

   for(int i = 0; i< n; i++){
      int x; cin >> x;
      if(a.empty()){
         a.push_back(x);
      }else if(x){
         if(a.back())a.back() = max(a.back(),x);
         else a.push_back(x);
      }else{
         if(a.back() || (sz(a) >= 2 && a[sz(a)-2]))a.push_back(x);
         else ans++;
      }
   }
   
   n = sz(a);
   vector<int> b;
   for(int i = 0; i < n; i++){
      if(a[i])b.push_back(i);
   }

   ans += sz(b);

   for(auto i: b){
      if(i && a[i-1] == 0){
         a[i]--;
         a[i-1]=1;
      }
      if(a[i] && i+1 < n && a[i+1] == 0){
         a[i]--,a[i+1]++;
      }
      a[i]=1;
   }
   for(int i = 0; i < n; i++){
      if(a[i] == 0)ans++;
   }
   cout << ans << endl;

}
 

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;  // cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

