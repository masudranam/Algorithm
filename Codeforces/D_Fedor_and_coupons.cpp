#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>using oset=tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>;
//*set.find_by_order(a) -> value at index a (0 based index)
//order_of_key(a) -> index or number (0 based index)

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
    int n, k; cin >> n >> k;

    oset<ar<int,2>> st;
    map<int,vector<ar<int,2>>>mp;
    vector<int> l(n),r(n);

    for(int i = 0; i < n; i++){
        cin >> l[i] >> r[i];
        st.insert({-r[i],i});
        mp[l[i]].push_back({-r[i],i});
    }

    sort(all(l));

    int cur = 0;

    for(int i = n-1; i >= 0; i--){
        if(sz(st) < k)continue;
        ar<int,2> a = *st.find_by_order(k-1);

        for(auto it: mp[l[i]]){
            st.erase(it);
        }

        if(-a[0] < l[i])continue;
        cur = max(cur,-a[0]-l[i]+1);
    }   
    st.clear();

    for(int i = 0; i < n; i++){
        st.insert({-r[i],i});
    }
    vector<int> ans;

    for(int i = n-1; i >= 0; i--){
        if(sz(st) < k)continue;
        ar<int,2> a = *st.find_by_order(k-1);

        if(-a[0]-l[i]+1 == cur){
            auto it = st.begin();
            while(k--){
                ans.push_back((*it)[1]+1);
                it++;
            }
            break;
        }

        for(auto it: mp[l[i]]){
            st.erase(it);
        }
        if(-a[0] < l[i])continue;
    }   

    for(int i = 1; i <= k && sz(ans) < k; i++){
        ans.push_back(i);
    }
    sort(all(ans));
    cout<<cur<<endl;
    print(ans);
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

