#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e3 + 10;

int dp[N][N][2];
int n, m;
string s, t;

int get(int i, int j, int f){
    if(i == n || j == m){
      // debug(i);debug(j);
        if(j == m)return (i != n && f == 0);
        return M;
    }
    int &ret = dp[i][j][f];
    if(ret != -1) return ret;
    ret = M;

    if(f){
        ret = get(i + 1, j, f);
    }
    if(s[i] == t[j]){
        ret = min(ret, get(i + 1, j + 1, 0));
        ret = min(ret, get(i + 1, j + 1, 1) + 1);
    }
    return ret;
}

void solve(){
    cin >> n >> m;
    cin >> s >> t;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            for(auto k : {0, 1}){
                dp[i][j][k] = -1;
            }
        }
    }
   
    int res = get(0, 0, 0);
    if(res >= M)cout << -1 << '\n';
    else cout << res << '\n';
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1; 
   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}
