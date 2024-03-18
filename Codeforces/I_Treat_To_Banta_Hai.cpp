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
    vector<int> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    int ans = 0, tmp = 0, s = 0;
    set<pair<int,int>> st;
    st.insert({0,n});

    for(int i = n-1; i >= 0; i--){
        s += a[i];  tmp += s;
        ans = max(ans, tmp);
        pair<int,int> p = *st.begin();
        ans = max(ans, tmp - (p.first)*(p.second - i));
        st.insert({tmp,i});
    }
    cout << ans << endl;
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;  // cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

