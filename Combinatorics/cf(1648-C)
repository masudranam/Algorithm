#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>using oset = tree<T, null_type, less<T>,
                       rb_tree_tag, tree_order_statistics_node_update>;
//*set.find_by_order(a) -> value at index a
//order_of_key(a) -> index or number

#define print(a) for(auto x:a)cout<<x<<" ";cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n';
#define all(a) (a).begin(),(a).end()
#define sz(a) (int)(a.size())
#define int   long long int
#define endl '\n'
#define ar array

const int M = 998244353;
const int N = 2e6 + 10;


int fact[N], inv[N], bit[N], a[N], b[N], cnt[N];

int pw (int a, int b) {
   int res = 1;
   while (b) {
      if (b & 1) res = (res * a) % M;
      a = (a * a) % M;
      b >>= 1;
   }
   return res;
}
void init() {
   fact[0] = 1;
   for (int i = 1; i < N; i++) fact[i] = (fact[i - 1] * i) % M;
   inv[0] = 1; inv[N - 1] = pw (fact[N - 1], M - 2);
   for (int i = N - 1; i > 0; i--) inv[i - 1] = (inv[i] * i) % M;
}

void add (int x, int y) { for (; x < N; x += x & -x) bit[x] += y; }
int sum (int x) {int res = 0; for (; x > 0; x -= x & -x) res += bit[x]; return res;}



void solve() {
   int n, m; cin >> n >> m;
   init();
   for (int i = 1; i <= n; i++) {
      cin >> a[i];
      add (a[i], 1);
      cnt[a[i]]++;
   }
   for (int i = 1; i <= m; i++) cin >> b[i];
   int cur = 1;

   for (int i = 1; i < N; i++) cur = (cur * inv[cnt[i]]) % M;

   int ans = 0;

   for (int i = 1; i <= min (n, m); i++) {
      int d = fact[n - i] * sum (b[i] - 1) % M;
      d = (d * cur) % M;
      ans = (ans + d) % M;
      if (!cnt[b[i]]) break;
      cur = (cur * cnt[b[i]]) % M;
      cnt[b[i]]--;
      if (i == n && m > n) ans += 1;
      add (b[i], -1);
   }

   cout << ans % M << endl;

}


signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1; //cin >> t;
   while (t--) solve();
   return 0;
}
