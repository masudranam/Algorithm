#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 500 + 10;

int dp[N][N], a[N];

int get(int l, int r){
    if(l > r) return 0;
    if(l == r) return 1;
    int &ret = dp[l][r];
    if(ret != -1) return ret;

    ret = 1 + get(l + 1, r);
    if(a[l] == a[l + 1]) ret = min(ret, 1 + get(l + 2, r));

    for(int i = l + 2; i <= r; i++){
        if(a[l] == a[i]){
            ret = min(ret, get(l + 1, i - 1) + get(i + 1, r));
        }
    }
    return ret;
}

void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << get(0, n - 1) << '\n';
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
