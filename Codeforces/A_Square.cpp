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
    int x[4], y[4];
    for(int i = 0; i < 4; i++){
        cin >> x[i] >> y[i];
    }
    for(int i = 0; i < 4; i++){
        for(int j = i+1; j < 4; j++){
            if(abs(x[i] - x[j])){
                cout<<abs(x[i]-x[j])*abs(x[i]-x[j])<<endl;
                return;
            }
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

