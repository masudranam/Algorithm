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
    int n, A, K;
    cin >> n >> A >> K;
    
    vector<ar<int,3>> a(n);
    for(int i = 0; i < n; i++){
        int p, f; cin >> f >> p;
        a[i] = {p-f,f,p};
    }
    sort(all(a));

    vector<int> pf(n+3),sf(n+3);

    multiset<int> st;
    int cur = 0;
    for(int i = 0; i < n; i++){
        st.insert(a[i][1]);
        cur += a[i][1];
        if(sz(st) > A){
            cur -= *st.begin();
            st.erase(st.begin());
        }
        pf[i+1] = cur;
    }
    st.clear();cur = 0;

    for(int i = n-1; i >= 0; i--){
        st.insert(a[i][2]);
        cur += a[i][2];
        if(sz(st) > K){
            cur -= *st.begin();
            st.erase(st.begin());
        }
        
        sf[i+1] = cur;
    }

    int ans = 0;
    for(int i = 0; i <= n; i++){
        ans = max(ans,pf[i]+sf[i+1]);
    }
    cout<<ans<<endl;
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

