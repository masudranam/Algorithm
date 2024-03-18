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
    vector<int> a(n+1);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<int> mx(n+2),mx1(n+1);
    multiset<int> st;
    st.insert(-1);

    for(int i = 0; i < n; i++){
        mx[i] = a[i]+i;
        st.insert(mx[i]);
    }
    multiset<int> st1;
    st1.insert(-1);

    for(int i = n-1; i >= 0; i--){
      mx1[i] = a[i] + (n-i-1);
    }

   int ans = M*M;
      for(int i = 0; i < n; i++){
         st.erase(st.find(mx[i]));
         int x = max(*st.rbegin(),*st1.rbegin());
         x = max(x,a[i]);
         ans = min(ans,x);
         st1.insert(mx1[i]);
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

