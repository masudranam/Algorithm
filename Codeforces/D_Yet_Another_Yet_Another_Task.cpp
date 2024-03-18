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
    int n; cin >> n;
    vector<int> a(n+1),pf(n+1);
    
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++){
        pf[i] = pf[i-1] + a[i];
    }

    multiset<int> st;
    vector<pair<int,int>>stk;

    stk.push_back({0,0});
    a[0] = M;

    int ans = 0;
    for(int i = 1; i <= n; i++){
        int mn = pf[i-1];
        while(a[stk.back().first] <= a[i]){
            mn = min(mn,stk.back().second);
            st.erase(st.find(a[stk.back().first] + stk.back().second));
            stk.pop_back();
        }
        stk.push_back({i,mn});
        st.insert(a[i]+mn);
        ans = max(ans,pf[i]-*st.begin());
    }

    cout << ans << endl;
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

