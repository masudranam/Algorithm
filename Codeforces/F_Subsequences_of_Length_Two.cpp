#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<endl
#define all(a) (a).begin(),(a).end()
#define sz(a) (int)(a.size())
//#define int   long long int
#define endl '\n'
#define ar array
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

int dp[205][205][205];
string s,t;
int n, k;

int get(int i, int j, int cnt){
    if(j > k)return -M;
    if(i == n)return 0;

    int &ret = dp[i][j][cnt];
    if(ret != -1)return ret;

    if(s[i] == t[0]){
        ret = get(i+1,j,cnt+1);
    }else{
        ret = get(i+1,j,cnt)+cnt*(s[i] == t[1]);
        ret = max(ret,get(i+1,j+1,cnt+1));
    }
    
    ret = max(ret,get(i+1,j+1,cnt)+cnt);
    return ret;
}

void solve(){
    cin >> n >> k;
    cin >> s >> t;
    memset(dp,-1,sizeof(dp));
    if(t[0] == t[1]){
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += s[i] == t[0];
        }
        ans = min(n,k+ans);
        cout<<ans*(ans-1)/2<<endl;
    }else{
        cout<<get(0,0,0)<<endl;
    }
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

