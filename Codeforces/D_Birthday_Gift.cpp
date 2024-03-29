#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<endl
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n, x;
    cin >> n >> x;

    vector<vector<int>>c(n+5,vector<int>(35));

    for(int i = 1; i <= n; i++){
        int a; cin >> a;
        for(int j = 0; j < 31; j++){
            if(a&(1ll<<j)){
                c[i][j] = 1;
            }
            c[i][j] =(c[i][j] + c[i-1][j])%2;
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

