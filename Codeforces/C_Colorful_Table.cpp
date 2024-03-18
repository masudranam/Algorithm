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
    int n, k;
    cin >> n >> k;
    vector<int> ans(k+1);

    set<int> st;
    multiset<int> idx;

    map<int,vector<int>>id;
    for(int i = 0; i < n;i ++){
        int x; cin >> x;
        id[x].push_back(i);
        st.insert(x);
        idx.insert(i);
    }

    for(auto x: st){
       // print(id[x]);
        int x1 = 2*abs(-id[x][0]+*idx.rbegin()+1);
        int y = 2*abs(id[x].back()-*idx.begin()+1);
        int z = 2*abs(*idx.rbegin() - *idx.begin() + 1);
        //debug(x1);debug(y);
        ans[x] = max({ans[x],z});
        for(auto val : id[x]){
            idx.erase(idx.find(val));
        }
    }
    for(int i = 1; i <= k; i++){
        cout<<ans[i]<<" \n"[i==k];
    }



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

