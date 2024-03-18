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

    vector<int> a(n),sf(n+1);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = n-2; i >= 0; i--){
        if(a[i] >= a[i+1])sf[i] = 1;
        sf[i] += sf[i+1];
    }
    int ans = sf[0], cur = 1;

    for(int i = 1; i < n; i++){
        cur += (a[i-1] <= a[i]);
        ans = min(ans, sf[i+1] + cur);
    }

    cout << ans << endl;
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

