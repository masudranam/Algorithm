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
    int n, q; 
    cin >> n >> q;
    vector<int> p(n+1),id[n+1];

    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        p[x] = i; 
    }

    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j += i){
            id[min(p[i],p[j])].push_back(max(p[i],p[j]));
        }
    }

    BIT bit(min(n,200000-5ll));

    vector<ar<int,2>> Q[n + 1];
    vector<int> ans(q);

    for(int i = 0; i < q; i++){
        int l, r; cin >> l >> r;
        Q[l].push_back({r,i});
    }


    for(int i = n; i >= 1; i--){
        for(auto x: id[i]){
            bit.upd(x,1);
        }
        for(auto x: Q[i]){
            ans[x[1]] = bit.qry(x[0]);
        }
    }

    for(int i = 0; i < q; i++){
        cout<<ans[i]<<'\n';
    }


}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

