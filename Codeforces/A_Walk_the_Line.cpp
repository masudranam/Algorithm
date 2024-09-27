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
    for(auto &x : a) cin >> x;
    sort(a.begin(),a .end());
    int tot = 2 * (n - 1) + 1;
    tot *= a[0];
    if(tot <= k) cout << "YES\n";
    else cout << "NO\n";
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);

   int t = 1;   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}
