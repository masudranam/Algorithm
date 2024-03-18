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
    int prv = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;

        int cur = (1ll<<x);
        
        bool f = (prv&(1ll<<x)) == 0;
        for(int j = x+1; j < 60; j++){
            if(f){
                cur += prv&(1ll<<j);
                continue;
            }
            if(!(prv&(1ll<<j))){
               cur += (1ll<<j);   
                f = 1;
            }
        }
        prv = cur;
    }
    cout << prv << endl;
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

