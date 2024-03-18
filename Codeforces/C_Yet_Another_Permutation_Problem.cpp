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
    int n;
    cin >> n;
    set<int> st;
    for(int i = 1; i <= n; i++){
        st.insert(i);
    }

    vector<int> v;

    for(int i = 2; i <= n; i++){
        int cur = i;
        if(st.find(i) == st.end())continue;
        if(st.find(2*i) == st.end())continue;
        while(1){
            auto it = st.lower_bound(cur);
            if(it != st.end()){
                v.push_back(*it);
                st.erase(it);
            }else break;
            cur *= 2;
        }
    }
    for(auto x: st)v.push_back(x);
    print(v);

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

