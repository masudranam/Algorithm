#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n; cin >> n;
    bool ok = true;
    vector<int> t{2, 2, 2, 1, 3};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 5; j++){
            vector<int> a(3);
            for(auto &x : a) cin >> x;
            if(a[1] != 3 || a[2] != 10)ok = false;
            if(t[j] != a[0])ok = false;
        }
    }
    if(ok)cout << "Consistent\n";
    else cout << "Inconsistent" << '\n';
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
