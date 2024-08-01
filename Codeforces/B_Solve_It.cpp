#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>using oset=tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>;
//*set.find_by_order(a) -> value at index a (0 based index)
//order_of_key(a) -> index of number a (0 based index)


#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;



void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n);

    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;

    oset<pair<int,int>> st;
    int res = 0;

    for(int i = 0; i < n; i++){
        auto it = st.order_of_key({b[i] - a[i],i});
        res += (st.size() - it);
        st.insert({a[i] - b[i], i});
    }
    cout << res << '\n';
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1; //  cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

