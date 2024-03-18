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

int n, k, x;
int dp[5005][5005],a[5005];

int get(int i, int cnt){
   if(i == n){
    if(cnt == x)return 0;
    return -M*M;
   }
   if(cnt > x)return -M*M;
   if(i+k-1 >= n){
    if(cnt == x)return 0;
   }

   if(dp[i][cnt] != -1)return dp[i][cnt];
   int res = -M*M;

   for(int j = i; j < min(n,i+k); j++){
    res = max(res, get(j+1,cnt+1) + a[j]);
   }
   return dp[i][cnt] = res;
}


void solve(){
    
    cin >> n >> k >> x;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    if(n/k > x || n < x){
        cout<<-1<<endl;
        return;
    }
    
    memset(dp,-1,sizeof(dp));

    cout << get(0,0) << endl;
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

