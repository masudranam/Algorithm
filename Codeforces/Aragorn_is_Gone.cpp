#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

int dp[101][101][101];
int a[N], n;

int get(int i, int s, int target, int cur){
    if(cur > target)return 0;
    
    if(i == n){
        return (s % target == 0) && (cur == target);
    }

    int &ret = dp[i][s][cur];

    if(ret != -1) return ret;
    
    int nw = (s + a[i]) % target;
    nw = (nw + target) % target;
    ret = 0;
    ret = (ret + get(i + 1, nw, target, cur + 1)) % M;
    ret = (ret + get(i + 1, s, target, cur)) % M;
    return ret;   
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            for(int k = 0; k <= n; k++){
                dp[i][j][k] = -1;
            }
        }
    }

    int ret = 0;
    for(int l = 1; l <= n; l++){
           for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            for(int k = 0; k <= n; k++){
                dp[i][j][k] = -1;
            }
        }
    }
        ret = (ret + get(0, 0, l, 0)) % M;
    }
    cout << ret << '\n';
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1; 
   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}
