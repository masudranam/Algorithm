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
    int n, m;
    cin >> n >> m;
    vector<int> a(m);

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        a[--x]++;
    }

    vector<vector<int>>dp(3,vector<int>(3,0));

    for(auto c: a){
        vector<vector<int>>tp(3,vector<int>(3,0));
        for(int x = 0; x < 3; x++){
            for(int y = 0; y < 3; y++){
                for(int z = 0; z < 3; z++){
                    if(c >= x + y + z){
                        tp[y][z] = max(tp[y][z],dp[x][y] + z + (c - x - y - z)/3);
                    }
                }
            }
        }
        dp = tp;
    }
    cout<<min((n-1)/3,dp[0][0])<<endl;
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

