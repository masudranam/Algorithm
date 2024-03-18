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
    int m, k, a1, ak;
    cin >> m >> k >> a1 >> ak;
 
    int ans = 0;
    if(ak*k >= m)m%=k;
    else m -= ak*k;
 
  
    int m1 = m;
    m -= a1;
    
 
    ans = (m/k + m%k);
    int x = m/k;
    
    if((x+1)*k <= m1){
      int ans1 = max(0ll,m1-(x+1)*k-a1);
      ans1 += x+1;
    
      ans = min(ans,ans1);
    }
    
 
 
 
   
    cout<<ans<<endl;
   
 
    
    
  
    
 
 
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
 