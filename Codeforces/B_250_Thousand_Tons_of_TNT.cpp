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
    
    vector<int> pf(n+1);
    int a[n+2];
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
   // sort(a+1,a+n+1);

    for(int i = 1; i <= n; i++){
        pf[i] = pf[i-1] + a[i];
    }

    int ans = 0;
  
    for(int k = 1; k <= n; k++){
        if(n%k)continue;
       // debug(k);

          int mx = 0, mn = M*M;
        for(int i = k; i <= n; i+=k){
            int x = pf[i]-pf[i-k];
            mn =min(mn,x);
            mx = max(mx,x);
        }
        ans = max(ans,mx-mn);
        //cout<<k<<' '<<mx<<' '<<mn<<endl;
    }
    
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

