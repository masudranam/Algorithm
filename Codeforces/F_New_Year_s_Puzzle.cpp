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
   map<int,int>mp;
   mp[n+1] = 3;

   for(int i = 0; i < m; i++){
      int x, y; cin >> x >> y;
      mp[y] |= (1<<(x-1));
   }
   int last = 0, Lcolour = 0;
   for(auto y: mp){
      int x = y.first, mask = y.second;
   //   cout << x <<' '<<mask<<endl;
      int colour = (x+mask)%2;
      if(last){
         if(mask == 3){
            cout<<"NO\n";return;
         }
         
         if(Lcolour == colour){
            cout<<"NO\n";return;
         }
         last = 0;
         Lcolour = colour;
      }else{
         if(mask != 3){
            last = 1;
            Lcolour = colour;
         }else{
            last = 0;
         }
      }
   }

   cout <<"YES\n";


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

