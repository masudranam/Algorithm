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
    int i, j;
    cin >> i >> j;

    // int ans = max({(m-j)*n,(j-1)*n,(n-i)*m,(i-1)*m});

    // if(i-2>=1){
    //     ans = max(ans,(i-2)*m+(m-j-1));
    // }
    // if(i+2<=n)
    // ans = max(ans,(n-i-2)*m + (m-j-1));

    // if(j-2>=1){

    // }

    int ans = max({(m-j)*n,(j-1)*n,(n-i)*m,(i-1)*m});
    cout<<ans<<endl;
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

