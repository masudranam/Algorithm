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

 vector<int> g[60];
void solve(){
    int n; cin >> n;
    for(int i = 0; i <= 50; i++)g[i].clear();

   multiset<int> st;
    vector<vector<int>> a(n);

    for(int i = 0; i < n; i++){
        int k; cin >> k;
        for(int j = 0; j < k; j++){
            int x; cin >> x;
            g[x].push_back(i);
            st.insert(x);
            a[i].push_back(x);
        }
    }

    int ans = 0;

    for(int i = 1; i <= 50; i++){
        if(sz(g[i]) == 0)continue;
        multiset<int> st1 =st;
        for(auto x: g[i]){
            for(auto y: a[x]){
                if(st1.find(y) != st1.end()){
                    st1.erase(st1.find(y));
                }
            }
        }
        set<int> z;
        for(auto x: st1)z.insert(x);
        ans = max(ans,sz(z));
    }

cout<<ans<<endl;


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

