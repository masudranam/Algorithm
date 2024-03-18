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
const int N = 65 + 10;

int dp[N][N][N][N];
int a[N][N],n,m,k;

int get(int i, int j, int c, int r){
    if(i == n){
        return (r == 0) ? 0: -M;
    }

    int &ret = dp[i][j][c][r];
    if(ret != -1)return ret;
    int ni = i, nj = j+1;
    if(j == m-1){
        nj = 0, ni = i+1;
    }
    ret = get(ni,nj,(nj == 0?0:c),r);
    int x = a[i][j];

    if(c < m/2){
        ret = max(ret,get(ni,nj,(nj == 0?0:c+1),(x+r)%k)+x);
    }
    return ret;
    
}

void solve(){
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));

    cout << get(0,0,0,0) << endl;

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

