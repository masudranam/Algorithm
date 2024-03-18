#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<endl
#define all(a) (a).begin(),(a).end()
#define sz(a) (int)(a.size())
//#define int   long long int
#define endl '\n'
#define ar array
 
const int M = 1e9 + 7;
const int N = 1e6 + 10;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> d[m+1],id[m+1];
    set<int> st;

    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        if(x > m)continue;
        id[x].push_back(i);
        st.insert(x);
    }

    for(auto it: st){
        int x = it;
        for(int j = x; j <= m; j += x){
            d[j].push_back(x);
        }
    }

    int mx = 0,lcm = 1;
    for(int i = 1; i <= m; i++){
        int cur = 0;
        for(auto x: d[i]){
            cur += sz((id[x]));
        }
        if(cur > mx){
            lcm = i;
            mx = cur;
        }
    }

    vector<int> ans;
    for(auto x: d[lcm]){
        for(auto y: id[x])ans.push_back(y);
    }

     sort(all(ans));
    cout<<lcm<<' '<<sz(ans)<<endl;
    print(ans);
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

