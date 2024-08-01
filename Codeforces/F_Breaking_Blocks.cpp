#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n; cin >> n;
    vector<int> a(n), s(n);
    for(int i = 0; i < n; i++){
        cin >> a[i], s[i] = a[i];
        if(i) s[i] += s[i-1];
    }
    int ans = 0;
    for(int i = n-1, cur = 0; i >= 0; i--){
        cur += a[i];
        auto it = lower_bound(s.begin(), s.end(), cur) - s.begin();
        if(it < i && s[it] == cur){
            ans = max(ans, it + 1 + n - i);
        }
    }

    cout << ans << '\n';
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

