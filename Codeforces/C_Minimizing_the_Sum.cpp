#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 3e5 + 10;

int dp[N][11],a[N];
int n;

int get(int i, int k){
    if(i >= n)return 0;
    if(dp[i][k] != -1)return dp[i][k];

    int res = get(i+1,k) + a[i];
    int mx = a[i];
    for(int j = 1; j <= k && i+j < n; j++){
        mx = min(mx,a[j+i]);
        res = min(res,get(i+j+1,k-j) + (j+1)*mx);
    }
    return dp[i][k] = res;
}

void solve(){
    cin >> n;
    int k; cin >> k;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= k; j++){
            dp[i][j] = -1;
        }
    }
    cout << get(0,k) << endl;
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

