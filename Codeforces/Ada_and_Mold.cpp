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
const int N = 5050;

int a[N], s[N][35];
int n, k;

int f(int l, int r){
    int res = 0;
    for(int i = 0; i < 31; i++){
        int o = s[r][i] - s[l-1][i];
        int z = r - l + 1 - o;
        res += (o*z*(1ll<<i));
    }
    return res;
}

int dp[N][N];

int get(int idx, int cur){
   // cout << idx<<' '<<cur<<endl;
    if(idx == n){
        if(cur == k)return 0;
        return M*M;
    }
    if(dp[idx][cur] != -1) return dp[idx][cur];

    int res = M * M;
    for(int i = idx; i <= n; i++){
        res = min(res, get(i+1,cur+1) + f(idx,i));
    }
    return dp[idx][cur] = res;
}

void solve(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 31; j++){
            if(a[i]&(1<<j))s[i][j]++;
            s[i][j] += s[i-1][j];
        }
    }
   //cout << f(4,6) << endl;

    int ans = M*M;
    memset(dp,-1,sizeof(dp));

   // cout << get(4,0) << endl;

    for(int i = 2; i <= n; i++){
        ans = min(ans, get(i,0) + f(1,i-1));
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

