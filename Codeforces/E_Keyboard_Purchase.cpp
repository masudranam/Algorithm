#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

struct BIT { //1-indexed
  int n; vector<int> t;
  BIT() {}
  BIT(int _n) {
    n = _n; t.assign(n + 5, 0);
  }
  int qry(int i) {
    int ans = 0;
    for (; i >= 1; i -= (i & -i)) ans += t[i];
    return ans;
  }
  void upd(int i, int val) {
    if (i <= 0) return;
    for (; i <= n; i += (i & -i)) t[i] += val;
  }
  void upd(int l, int r, int val) {
    upd(l, val);
    upd(r + 1, -val);
  }
  int qry(int l, int r) {
    return qry(r) - qry(l - 1);
  }
};

void solve(){
    BIT bit(N);
    bit.upd(2, 10, 10);
    bit.upd(5, 7, 5);
    bit.upd(3, 8, 3);
    for(int i = 2; i <= 10; i++){
        cout << bit.qry(i) << ' ';
    }
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1; 
  // cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}
