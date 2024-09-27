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
    for (; i >= 1; i -= (i & -i)) ans = max(t[i], ans);
    return ans;
  }
  void upd(int i, int val) {
    if (i <= 0) return;
    for (; i <= n; i += (i & -i)) t[i] = max(t[i], val);
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
    int n, m;
    cin >> n >> m;
    vector<int> l(n+1),r[n+1], f(n+2);

    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        r[y].push_back(x);
        l[x]++;
        f[x]++, f[y+1]--;
    }
    multiset<int> st;
    vector<int> mn(n+1,n+1);

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < l[i]; j++){
            st.insert(i);
        }
        int t = i;
        if(st.size())t = *st.begin();
        mn[i] = min(mn[i], t);
        for(auto it : r[i]){
            st.erase(st.find(it));
        }
    }

    for(int i = 1; i <= n; i++){
        f[i] += f[i-1];
    }

    int ans = 0;
    BIT bit(n);

    for(int i = 1; i <= n; i++){
        int val = bit.qry(mn[i]-1);
        ans = max(ans, val + f[i]);
        bit.upd(i,f[i] + val);
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
