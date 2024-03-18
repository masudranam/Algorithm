#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<endl
#define all(a) (a).begin(),(a).end()
#define sz(a) (int)(a.size())
//#define int   long long int
#define endl '\n'
#define ar array
 
const int M = 18;
const int N = (1<<M) + 10;

int cnt[M][M];
int d[M],n,m;
string s;
int dp[N];

int get(int mask){
    int already = __builtin_popcount(mask);
    if(already == m)return 0;
    if(dp[mask] != -1) return dp[mask];

    int ret = (1<<30);
    for(int i = 0; i < m; i++){
        if(mask & (1<<i))continue;
        int cur =  0;
        for(int j = 0; j < m; j++){
            if(mask & (1<<j))cur += cnt[i][j];
        }
        ret = min(ret,get(mask|(1<<i)) + cur*already - (d[i]-cur)*already);
    }
    return dp[mask] = ret;
}

void solve(){
    cin >> n >> m;
    cin >> s;
    for(int i = 1; i < n; i++){
        if(s[i] == s[i-1])continue;
        cnt[s[i]-'a'][s[i-1]-'a']++;
        cnt[s[i-1]-'a'][s[i]-'a']++;
        d[s[i]-'a']++, d[s[i-1]-'a']++;
    }

    memset(dp,-1,sizeof(dp));

    cout<<get(0)<<endl;
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

