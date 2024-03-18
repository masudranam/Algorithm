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
    int d; cin >> d;

    vector<int> a(n+2);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    multiset<int> st;

    for(int i = 1; i <= n; i++){
        st.insert(a[i]-a[i-1]);
    }

    auto rmv = [&](int i){
        st.erase(st.find(a[i]-a[i-1]));
        st.erase(st.find(a[i+1]-a[i]));
        st.insert(a[i+1]-a[i-1]);
    };

    auto add = [&](int i){
        st.erase(st.find(a[i+1]-a[i-1]));
        st.insert(a[i]-a[i-1]);
        st.insert(a[i+1]-a[i]);
    };

    int ans = 0;

    for(int i = 1; i < n; i++){
       rmv(i);
       int x = max(2*(d-a[n]),*st.rbegin());
       ans = max(ans, min(*st.begin()-1,(x-2)/2));
       add(i);
    }

    st.erase(st.find(a[n]-a[n-1]));
    
    ans = max(ans, min(*st.begin()-1,(*st.rbegin()-2)/2));
    ans = max(ans,min(*st.begin()-1,d-a[n-1]-1));

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

