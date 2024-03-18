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
const int N = 2e6 + 10;

void solve(){

    int n, k;
    cin >> n >> k;
    set<int> st;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        st.insert(x);
    }
  

    for(int i = N-k; i >= 1; i--){
        bool ok = true;
        for(int j = k; j < N; j += i){
            auto it = st.upper_bound(j);
            if(it == st.end())it--;
            if((*it) % i > k){
                ok = false;break;
            }
        }

        if(ok){
            cout<<min(i,*st.begin())<<endl;return;
        }
    }

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

