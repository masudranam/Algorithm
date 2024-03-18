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
    int n = sz(s);

    int m; cin >> m;
    vector<string> v(m);
    for(auto &x : v) cin >> x;

    vector<pair<int,int>> dp(n+1,{n+1,0});
    dp[0].first = 0;

    s = "#" + s;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < m; j++){
            int x = sz(v[j]);
            if(i + x - 1 <= n && s.substr(i,x) == v[j] && dp[i+x-1].first > dp[i-1].first+1){
                dp[i+x-1] = {dp[i-1].first+1,j};
                for(int k = i + x -1; k >= i; k--){
                    dp[k] = min(dp[k],dp[i+x-1]);
                }
            }
        }
    }
    if(dp[n].first >= n+1){
        cout << -1 << endl;
        return ;
    }

    vector<ar<int,2>> ans;
    int j = dp[n].first;

    for(int i = n; i >= 1; i--){
        if(dp[i].first == j){
            ans.push_back({dp[i].second, i - sz(v[dp[i].second])+1});
            j--;
        }
    }

    cout<< sz(ans) << endl;
    for(auto it : ans){
        cout << it[0] +1 <<' '<< it[1] << endl;
    }
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

