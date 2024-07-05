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
const int N = 1e6 + 100;
int cnt[N];
void solve() {
   int n, m;
   cin >> n >> m;

   vector<int> dp (m + 1, 0);
   vector<int> a (n), b (n);
   for (int i = 0; i < n; i++) cin >> a[i];
   for (int i = 0; i < n; i++) cin >> b[i];

   dp[0] = 1;
   int ans = 0;
   for (int i = 0; i < n; i++) {
      for (int j = a[i]; j <= m; j++) {
         if (dp[j] || !dp[j - a[i]]) continue;
         if (cnt[j - a[i]] == b[i]) {
            cnt[j] = b[i]; continue;
         }
         ans++;
         dp[j] = 1;
         cnt[j] = cnt[j - a[i]] + 1;
      }
      for (int j = 0; j <= m; j++) cnt[j] = 0;
   }

   cout << ans << '\n';
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1; // cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      cout << "Case " << tc << ": ";
      solve();
   }
   return 0;
}

