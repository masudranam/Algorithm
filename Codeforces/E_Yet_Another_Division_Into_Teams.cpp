#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n; cin >> n;
    vector<pair<int,int>> a(n);
    vector<int> dp(n + 1, M), par(n + 1);

    for(int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());

    for(int i = 0; i < n; i++){
        for(int j = 2; j <= 4 && i + j < n; j++){
            int cur = (i ? dp[i - 1] : 0) + (a[i + j].first - a[i].first);
            if(cur < dp[i + j]){
                dp[i + j] = cur;
                par[i + j] = i - 1;
            }
        }
    }

    vector<int> res(n);

    int cnt = 1, cur = n - 1;
    while(cur > 0){
        int u = par[cur];
        for(int i = u + 1; i <= cur; i++){
            res[a[i].second] = cnt;
        }
        cnt++;
        cur = u;
    }
 
    cout <<dp[n - 1] <<' '<< cnt - 1 <<'\n';
    for(int i = 0; i < n; i++){
        cout << res[i] <<' ';
    }
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1; 
  // cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}
