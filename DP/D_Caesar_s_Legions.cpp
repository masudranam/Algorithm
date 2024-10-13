#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e8;
const int N = 102;

int dp[N][N][2][11];
int K1, K2, N1 , M1;

int get(int n, int m, int cnt, int f){
    if(n + m == N1 + M1) return 1;
    int &ret = dp[n][m][f][cnt];
    if(ret != -1)return ret;
    ret = 0;

    if(f){
        if(cnt < K2 && m < M1)ret = (ret + get(n, m + 1, cnt + 1, f)) % M;
        if(n < N1){
            ret = (ret + get(n + 1, m, 1, 0)) % M;
        }
    }else{
        if(cnt < K1 && n < N1){
            ret = (ret + get(n + 1, m, cnt + 1, f)) % M;
        }
        if(m < M1){
            ret = (ret + get(n, m + 1, 1, 1)) % M;
        }
    }
    return ret;
}


void solve(){
    
    cin >> N1 >> M1 >> K1 >> K2;
    memset(dp, -1, sizeof(dp));

    cout << get(0, 0, 0, 0) << '\n';
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1; 
   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}
