#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;


void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    int x = 0;
    while((x+1) * (x + 2) / 2 <= k){
      x += 1;
    }

    for(int i = 0; i < n; i++){
      if(i < x){
         a[i] = 2;
      }else if(i == x){
         a[i] = -2*x - 1 + 2 * (k - x*(x + 1) / 2);
      }else{
         a[i] = -1000;
      }
    }
    print(a);
   
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
