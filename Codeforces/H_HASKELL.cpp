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

void solve(){
    int n, m;
    cin >> n >> m;
    set<int> st;

    for(int i = 0; i < n; i++){
        st.insert(i);
    }
    vector<ar<int,2>> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i][1] >> v[i][0];
    }
    sort(all(v)); reverse(all(v));
    int ans = 0;

    for(int i = 0; i < n; i++){
        int profit = v[i][0], days = v[i][1];
        auto it = st.upper_bound(m-days);
        if(it != st.begin()){
            it--;
            st.erase(*it);
            ans += profit;
        }
    }
    cout<<ans<<endl;
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

