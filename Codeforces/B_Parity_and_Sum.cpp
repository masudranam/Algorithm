#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n; cin >> n;
    vector<int> a(n);

    int odd = 0, mn = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i]&1){
            odd++;
            mn = max(mn, a[i]);
        }
    }
    if(odd == 0 || odd == n){
        cout << 0 << '\n'; return;
    }

    int res = 0, extra = 0;

    sort(a.begin(), a.end());

    for(int i = 0; i < n; i++){
        if(a[i]&1)continue;
        if(a[i] > mn){
            extra = 1;
        }
        mn += a[i];
        res++;
        
    }
    cout << res + extra << '\n';

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