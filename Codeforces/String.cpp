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
    string s; cin >> s;
    int k; cin >> k;
    int n = sz(s);
    if(n*(n+1)/2 < k){
        cout<<"No such line.\n";
        return;
    }

    multiset<pair<string,int>>st;

    for(int i = 0;i < n; i++){
        string t; 
        t += s[i];
        st.insert({t,i});
    }
    k--;
    
    while(k--){
        auto it = *st.begin();
        st.erase(st.begin());
        if(it.second + 1 < n){
            it.second++;
            it.first += s[it.second];
            st.insert(it);
        }
    }
    cout<<(*st.begin()).first<<endl;

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

