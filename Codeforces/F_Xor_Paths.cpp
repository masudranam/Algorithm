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
int n, m, k;

map<int,int>dp[25][25];
int a[30][30], half;

void getUP(int i, int j,int xr,int cnt){
    if(cnt == half){
        dp[i][j][xr^a[i][j]]++;
        return;
    }
    if(i + 1 < n)getUP(i+1,j,xr^a[i][j],cnt+1);
    if(j+1 < m)getUP(i,j+1,xr^a[i][j],cnt+1);  
}

int getDown(int i, int j , int xr, int cnt){
    if(cnt == n+m-2-half){
        return dp[i][j][k^xr];
    }
    int res = 0;
    if(i > 0)res = getDown(i-1,j,xr^a[i][j],cnt+1);
    if(j > 0) res += getDown(i,j-1,xr^a[i][j],cnt+1);
    return res;
}
void solve(){
    cin >> n >> m >> k;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    half = (n+m-2)/2;

    getUP(0,0,0,0);

    cout<< getDown(n-1,m-1,0,0) << endl;

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

