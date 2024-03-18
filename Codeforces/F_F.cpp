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
const int N = 2e6 + 10;

struct BIT { //1-indexed
  int n; vector<int> t;
  BIT() {}
  BIT(int _n) {
    n = _n; t.assign(n + 5, 0);
  }
  int qry(int i) {
    int ans = 0;
    if(i <= 0)return 0;
    for (; i >= 1; i -= i&-i) ans = max(ans,t[i]);
    return ans;
  }
  void upd(int i, int val) {
    if (i <= 0) return;
    for (; i <= n; i += i&-i) t[i] = max(t[i],val);
  }
};

void solve(){
    int n; cin >> n;
    vector<int> h(n+1),a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> h[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    BIT bit(n);

    int ans = 0;
    for(int i = 1; i <= n; i++){
        int val = bit.qry(h[i]-1) + a[i];
        ans = max(ans,val);
        bit.upd(h[i],val);
    }
    cout<<ans<<endl;
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;  //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

