#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 998244353;
const int N = 2e5 + 10;

int a[N], dp[N][5][4], n;

int get(int i, int mask, int len){
    if(i == n){
        return len > 2;
    }
    int &ret = dp[i][mask][min(3ll,len)];
    if(ret != -1) return ret;
    ret = get(i + 1, mask, len);

    if(len < 2){
        ret += get(i+1, (mask<<1)|(a[i]), len + 1);
        ret %= M;
    }else{
        int x = mask&1;
        x += ((mask >> 1)&1);
        x += a[i];
        if(x % 2 == 0){
            ret = (ret + get(i + 1, ((mask&1)<<1) | a[i], len + 1)) % M;
        }
    }
    return ret % M;
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i] %= 2;
    }

    memset(dp, -1, sizeof(dp));
    cout << get(0, 0, 0) % M<< '\n';
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