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

int dp[20][2][10][2];
string s;

int get(int idx,int choto,int prv,bool st){
    if(idx == sz(s)){
        return 1;
    }
    if(prv != -1 && dp[idx][choto][prv][st] != -1){
        return dp[idx][choto][prv][st];
    }
    int res = 0;
    
    for(int i = 0; i <= (choto?9:s[idx]-'0');i++){
       if(st && i == prv)continue;
       res += get(idx+1,choto|(i<(s[idx]-'0')),i,st|i);
    }
    return dp[idx][choto][prv][st] = res;
}

void solve(){
   int a , b; 
   cin >> a >> b;
   s = to_string(b);
   memset(dp,-1,sizeof(dp));
    b = get(0,0,0,0);
   if(a == 0){
    cout<<b<<endl;return;
   }
   memset(dp,-1,sizeof(dp));
   a--;
   s = to_string(a);
   a = get(0,0,0,0);
   
   cout<<b-a<<endl;
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

