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
    int n, k, a, b;
    cin >> n >> k >> a >> b;
    a--, b--;
    int x[n],y[n];
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
    if(k >= max(a+1,b+1)){
        cout<<0<<endl;
        return;
    }
    int fs = M*M, sc = M*M;
    int ans = abs(x[a]-x[b])+abs(y[a]-y[b]);
    for(int i = 0; i < k; i++){
        fs = min(fs,abs(x[i]-x[a])+abs(y[i]-y[a]));
        sc = min(sc,abs(x[i]-x[b])+abs(y[i]-y[b]));
    }
    ans = min(ans,fs+sc);
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

