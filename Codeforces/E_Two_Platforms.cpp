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
    int n, k;
    cin >> n >> k;

    vector<int> x(n),y(n);

    for(int i = 0; i < n; i++){
        cin >> x[i];
    }

    for(int i = 0; i < n; i++){
        cin >> y[i];
    }

    sort(all(x));

    multiset<ar<int,2>> st;
    st.insert({0,n});

    for(int i = 0, j = 0; i < n; i++){
        auto it = upper_bound(all(x),x[i]+k)-x.begin();
        y[i] = it-i;
        st.insert({it-i,i});
    }

    int ans = 0;

    for(int i = 0, j = 0; i < n; i++){
       while(j < n && x[j]-x[i] <= k){
        st.erase(st.find({y[j],j}));
        j++;
       }
       ans = max(ans,j-i+(*st.rbegin())[0]);
    }
    cout<<ans<<endl;
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

