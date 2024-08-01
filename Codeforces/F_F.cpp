#include<bits/stdc++.h>
using namespace std;

const int N = 302;
int dp[N][N][N];
int K;
string s;

int get(int l, int r, int k){
    if(l > r) return 0;
    if(l == r) return 1;

    int &ret = dp[l][r][k];
    if(ret != -1) return ret;
    ret = 0;
    if(s[l] == s[r])ret = get(l+1,r-1,k) + 2;
    else{
        if(k > 0) ret = max(ret, get(l+1,r-1,k-1)+2);
        ret = max(ret, max(get(l+1,r,k),get(l,r-1,k)));
    }
    return ret;
}

void solve(){
    cin >> s;
    cin >> K;

    memset(dp,-1,sizeof(dp));
    cout << get(0,s.size()-1,K) << '\n';
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

