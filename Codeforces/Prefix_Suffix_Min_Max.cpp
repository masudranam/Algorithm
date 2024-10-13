#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n; cin >> n;
    vector<int> b(n), a(n);

    for(int i = 0; i < n; i++){
        cin >> b[i];
    }

    cout << 2000000 <<' ';
    int s = 2e6, mx = 2e6;

    for(int i = 1; i < n; i++){
       int x = b[i] - s + mx;
       mx = max(mx, x);
       s += x;
       cout << x <<' ';
    }
    cout << '\n';



}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1; 
   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}
