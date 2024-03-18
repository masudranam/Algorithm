#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>using oset=tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>;
//*set.find_by_order(a) -> value at index a (0 based index)
//set.order_of_key(a) -> index of number a (0 based index)



#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<endl
#define all(a) (a).begin(),(a).end()
#define sz(a) (int)(a.size())
#define int   long long int
#define endl '\n'
#define ar array
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n; cin >> n;

   vector<ar<int,3>> v;

   for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        v.push_back({a,b,0});
        v.push_back({b,a,1});
   }

   sort(all(v));

   oset<int> st;

   int ans = 0;

   for(int i = 0; i < sz(v); i++){
    if(v[i][2] == 1){
        st.erase(v[i][0]);
    }else{
       ans +=sz(st) - st.order_of_key(v[i][1]);
       st.insert(v[i][1]);
    }
   }

   cout << ans << endl;



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

