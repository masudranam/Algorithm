#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n; cin >> n;
    set<int> st;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        st.insert(x);
    }
    vector<int>v(st.begin(),st.end());

    if(v[0] > 1){
        cout << "Alice\n";return;
    }
    n = v.size();
    if(n == 1){
        cout << "Alice\n";return;
    }

    for(int i = 1, last = 0; i < n; i++){
        if(v[i] - v[i-1] != 1){
            if(i%2 == 0)cout << "Alice\n";
            else cout << "Bob\n";
            return;
        }
    }
    if(n%2 == 1)cout << "Alice\n";
    else cout << "Bob\n";
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

