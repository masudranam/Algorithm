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

    vector<string> s(n);
    vector<vector<int>>dp(n,vector<int>(n,N));

    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    string ans;
    dp[0][0] = (s[0][0] != 'a');
   
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i)dp[i][j] = min(dp[i][j],dp[i-1][j] + (s[i][j] != 'a'));
            if(j)dp[i][j] = min(dp[i][j],dp[i][j-1] + (s[i][j] != 'a'));
            //debug(dp[i][j]);
            if(dp[i][j] <= k){
                while(i+j >= sz(ans))ans += 'a';
            }
        }
    }

    vector<pair<int,int>> id;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(dp[i][j] <= k && i+j+1 == sz(ans)){
                id.push_back({i,j});
            }
        }
    }

    if(sz(ans) == 0){
        ans += s[0][0];
        id.push_back({0,0});
    }
    vector<vector<int>>vis(n,vector<int>(n));

    while(true){
        vector<pair<int,int>> nxt;
        char c = 'z' + 1;
        for(auto i : id){
            if(i.first + 1 < n)c = min(c,s[i.first+1][i.second]);
            if(i.second + 1 < n)c = min(c,s[i.first][i.second+1]);
        }
        if(c > 'z')break;
        for(auto i : id){
            if(i.first + 1 < n && s[i.first+1][i.second] == c && !vis[i.first + 1][i.second]){
                nxt.push_back({i.first+1,i.second});
                vis[i.first+1][i.second] = true;
            }
            if(i.second + 1 < n && s[i.first][i.second+1] == c && !vis[i.first][i.second+1]){
                nxt.push_back({i.first, i.second+1});
                vis[i.first][i.second+1] = true;
            }
        }
        ans += c;
        id = nxt;
    }

    cout << ans << endl;

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

