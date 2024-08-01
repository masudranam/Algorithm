#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n; cin >> n;
    int tot = 2 * (n - 1) - n;

    multiset<array<int,3>> st;

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        st.insert({3*x,x,1});
    }

    while(tot > 0){
        array<int,3> p = *st.begin();
        st.erase(st.begin());
        p[2]++;
        p[0] = (2*p[2] + 1)*p[1];
        st.insert(p);
        tot--;
    }

    int res = 0;
    for(auto it : st){
       // cout << it[2] <<' ' << it[3] << '\n';
        res += (it[2]*it[2]*it[1]);
    }
    cout << res << '\n';

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

