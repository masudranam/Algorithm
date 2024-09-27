#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
//#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n, d, k;
    cin >> n >> d >> k;


    vector<int> g[n + 1], left;
    multiset<int> st;


    for(int i = 0; i < k; i++){
        int l, r; cin >> l >> r;
        left.push_back(l);
        g[l].push_back(r);
    }
    sort(left.begin(), left.end());

    pair<int,int> mx{0, 0}, mn{k + 1, 0};

    for(int i = 1; i <= n - d + 1; i++){
       auto it = lower_bound(left.begin(), left.end(), i + d) - lower_bound(left.begin(),left.end(),i);
       int cur = it + st.size();
       mx = max(mx, {cur, -i});
       mn = min(mn, {cur, i});
       for(auto r : g[i])st.insert(r);
       while(st.size() && *st.begin() <= i){
        st.erase(st.begin());
       }
    }
    cout << -mx.second <<' ' <<mn.second <<'\n';
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
