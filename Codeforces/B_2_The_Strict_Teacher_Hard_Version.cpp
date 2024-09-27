#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(m);
    for(auto &x : a) cin >> x;
    sort(a.begin(), a.end());

    for(int i = 0; i < q; i++){
        int x; cin >> x;
        auto it = lower_bound(a.begin(), a.end(), x);
        if(it == a.begin()){
            cout << (*it) - 1 << '\n';continue;
        }
        if(it == a.end()){
            it--;
            cout << (n - (*it)) << '\n';continue;
        }
        int y = *it;
        it--;
        cout << (y - (*it)) / 2 << '\n';
    }
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
