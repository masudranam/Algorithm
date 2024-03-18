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
 
int dp[20][130][130][2];
string s;
 
int get(int idx,int cur,int sum,int rem, int choto){
    if(idx == sz(s)){
        return cur == 0 && sum == rem;
    }
    
    if(dp[idx][cur][sum][choto] != -1){
        return dp[idx][cur][sum][choto];
    }
    int res = 0;
    
    for(int i = 0; i <= (choto?9:s[idx]-'0');i++){
        int x = (cur*10 + i) % rem;
        int t_sum = sum + i;
       res += get(idx+1,x,t_sum,rem,choto|(i<(s[idx]-'0')));
    }
    return dp[idx][cur][sum][choto] = res;
}
 
void solve(){
   int a ; cin >> a;

   s = to_string(a);
   
   int ans = 0;

   for(int i = 1; i <= 130; i++){
    memset(dp,-1,sizeof(dp));
    ans += get(0,0,0,i,0);
   }
   
   cout << ans << endl;
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
