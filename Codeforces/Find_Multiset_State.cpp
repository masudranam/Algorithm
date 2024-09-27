#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n; cin >> n;
    int k; cin >> k;

    set<pair<int,int>> st;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        st.insert({x, i});
    }
    while(k--){
        pair<int,int> f = *st.begin();
        pair<int,int> s = *st.rbegin();
        st.erase(st.begin());
        st.erase(--st.end());
        s.first += f.first;
        st.insert(s);
    }
    vector<int> res(n, - 1);
    for(auto it : st){
        cout << it.first <<' ';
    }
    cout << '\n';
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
