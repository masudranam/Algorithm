#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<endl
#define all(a) (a).begin(),(a).end()
#define sz(a) (int)(a.size())
#define int   long long int
#define endl '\n'
#define ar array

const int M = 1e9 + 7 ;
const int N = 500 + 10;


int dp[1005][1005][11][2];
void Max(int &a, int b){a=max(a,b);}

string s,t;
int n,m,k;
string tmp="";
int get(int i, int j, int cnt, bool f){
   if(cnt>k)return -M;
   if(i==n){
      if(cnt!=k)return -M;
      else return 0;
   }
   if(j==m){
      if(cnt!=k)return -M;
      else return 0;
   }

   int &ret=dp[i][j][cnt][f];
   if(ret!=-1)return ret;
   ret=0;

   if(s[i]==t[j]){
      ret=max(ret,get(i+1,j+1,cnt+1,1)+1);
      if(f)ret=max(ret,get(i+1,j+1,cnt,1)+1);
   }
      ret=max(ret,get(i+1,j,cnt,0));
      ret=max(ret,get(i,j+1,cnt,0));

   return ret;
}



void solve(){
   cin>>n>>m>>k;
   cin>>s>>t;

   for(int i=1; i<=n; i++){
      for(int j=1; j<=m; j++){
         for(int l=1; l<=k; l++){
            Max(dp[i][j][l][0],dp[i][j-1][l][0]);
            Max(dp[i][j][l][0],dp[i-1][j][l][0]);
            if(s[i-1]==t[j-1]){
               Max(dp[i][j][l][1],dp[i-1][j-1][l-1][0]+1);
               Max(dp[i][j][l][1],dp[i-1][j-1][l][1]+1);
            }

            Max(dp[i][j][l][1],dp[i][j][l-1][1]);
            Max(dp[i][j][l][0],dp[i][j][l-1][0]);
            Max(dp[i][j][l][0],dp[i][j][l][1]);
         }
      }
   }
   cout<<dp[n][m][k][0]<<endl;

}

signed main() {
    ios_base::sync_with_stdio (0);
    cin.tie (0);

    int t = 1;   // cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        //cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}
