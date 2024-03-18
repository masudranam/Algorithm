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
    int n;
    cin >> n;
    int mx = 0, mn = M;

    int ans = 0;
    vector<int> a(n), b(n);
    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;

    for(int i = 0; i < n; i++){
        if(a[i] > b[i])swap(a[i],b[i]);
        ans += b[i]-a[i];
        mx = max(a[i],mx);
        mn = min(b[i],mn);
    }
    cout<<ans + 2*max(0ll,mx-mn)<<endl;
  
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

