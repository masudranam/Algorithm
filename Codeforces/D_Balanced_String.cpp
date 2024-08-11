#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
//#define int   long long int

const int M = 1e9 + 7;
const int N = 101;

int dp[N][N][N*N/2], n, cnt0;
string s;

int get(int i, int c0, int need){
    if(i == n){
        if(c0 == cnt0 && need == (cnt0 * (n - cnt0) / 2)) return 0;
        return M;
    }
    int &ret = dp[i][c0][need];
    if(ret != -1) return ret;
    ret = get(i+1, c0 + 1, need);
    ret = min(ret, get(i+1, c0, need + c0) + (s[i] != '1'));
    return ret;
}

void solve(){
    cin >> s;
    n = s.size();
    cnt0 = count(s.begin(),s.end(),'0');
    memset(dp,-1,sizeof(dp));
    cout << get(0,0,0) << '\n';
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;  // cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}