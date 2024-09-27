#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n; cin >> n;
    multiset<int> st;

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        st.insert(x);
    }
    vector<int> b(n);
    for(auto &x : b){
        cin >> x;
    }

    for(int i = n-1; i >= 0; i--){
        auto it = st.upper_bound(b[i]);
        if(it == st.begin()){
            cout << i + 1 << endl;return;
        }
        it--;
        st.erase(st.find(*it));
    }
    cout << 0 << endl;
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

