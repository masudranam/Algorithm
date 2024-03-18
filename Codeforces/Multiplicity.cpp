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
const int N = 1e6 + 10;

 vector<int> d[N];

void solve(){
   
    for(int i = 1; i < N; i++){
        for(int j = i; j < N; j += i){
            d[j].push_back(i);
        }
    }

    for(int i = 0; i < N; i++){
        reverse(all(d[i]));
    }

    int n; cin >> n;

    vector<int> dp(N+1);
    int ans = 0;
    dp[0] = 1;

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        for(auto y : d[x]){
            ans = (ans + dp[y-1]) % M;
            dp[y] = (dp[y-1] + dp[y]) % M;
        }
    }


    cout << ans << endl;
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;  // cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

