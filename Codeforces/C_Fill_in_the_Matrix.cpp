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
    
   int n, m;
   cin >> n >> m;
   if(m == 1){
    cout<<0<<endl;
    for(int i = 0; i < n; i++){
      cout<<0<<endl;
    }
    return;
   }
   cout<<min(n+1,m)<<endl;

   for(int i = 0; i < n; i++){
    vector<int> a(m);
    iota(all(a),0);
    int p = max(1ll,m-i-1);
    reverse(a.begin(),a.begin()+p);
    reverse(a.begin()+p,a.end());
    print(a);
   }
   

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
 