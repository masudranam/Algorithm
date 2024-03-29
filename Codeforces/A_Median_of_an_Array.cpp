#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<endl
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n;cin >> n;
    vector<int> a(n);
    for(auto &x : a)cin >> x;
    sort(a.begin(),a.end());

    int x = a[(n-1)/2]+1;
    int ans = 0;
    //debug(x);
    for(int i = (n-1)/2; i < n; i++){
        ans += max(0ll, x - a[i]);
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

