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
    int a[n][n];

    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            cin >> a[i][j];
        }
    }

    vector<int> dp[n+2];
    dp[n] = dp[n+1] = {0};

    for(int i = n-1; i >= 0; i--){
        priority_queue<pair<int,int>> pq;
        vector<int> p(n+2);
        for(int j = i + 2; j <= n + 1; j++){
            p[j] = 0;
            pq.push({dp[j][p[j]] + a[i][j-2], j});
        }

        for(int f = 0; f < k && !pq.empty(); f++){
            auto it = pq.top();
            pq.pop();
            dp[i].push_back(it.first);
            p[it.second]++;
            if(p[it.second] < dp[it.second].size()){
                pq.push({dp[it.second][p[it.second]] + a[i][it.second-2], it.second});
            }
        }
        for(auto j : dp[i+1])dp[i].push_back(j);
      //  print(dp[i]);
        sort(dp[i].rbegin(), dp[i].rend());
        while(dp[i].size() > k)dp[i].pop_back();
    }
    for(auto i : dp[0]) cout << i <<' ';
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
