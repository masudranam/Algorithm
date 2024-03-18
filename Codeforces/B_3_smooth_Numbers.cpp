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

bool ok(int x){
    while(x % 3 == 0)x/=3;
    return (x == 1);
}

void solve(){
    int n; cin >> n;

    for(int i = 1; i <= n; i = i*2){
        if(n%i)continue;
        if(ok(n/i)){
            cout<<"Yes\n";
            return;
        }
    }
    cout<<"No\n";
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

