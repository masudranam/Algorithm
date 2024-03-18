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
    int n, s;
    cin >> n >> s;
    vector<vector<int>>v(n,vector<int>(s,0));
    for(int i = 0; i < n; i++){
        for(int j = 0;j < s; j++){
            cin >> v[i][j];
        }
    }
    set<int> st;
    for(int i = 0; i < s; i++){
        for(int j = 0; j < n; j++){
            st.insert(v[j][i]);
        }
        if(sz(st) == i+1){
            cout<<sz(st)<<endl;
            print(st);
            return;
        }
    }

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;  // cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

