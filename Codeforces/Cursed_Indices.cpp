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
    
    multiset<int> st;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        st.insert(x);
    }

    vector<int> a(1);
    a[0] = *st.begin();
    st.erase(st.begin());

    int ans = 0,cur = a[0];

    while(sz(st)){
        auto it = st.upper_bound(cur);
        if(it == st.end()){
            it--;
            a.push_back(*it);
            cur += *it;
            ans++;
            st.erase(it);
        }else{
            a.push_back(*it);
            cur += *it;
            st.erase(it);
        }
    }
    cout<<ans<<endl;
    print(a);
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

