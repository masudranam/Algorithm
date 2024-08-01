#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n; cin >> n;
    vector<int> a(n+1), cnt(n+1);

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x > n)continue;
        cnt[x]++;
    }
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j += i){
            a[j] += cnt[i];
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, a[i]);
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

