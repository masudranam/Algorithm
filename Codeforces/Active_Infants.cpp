#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e3 + 10;

int dp[N][N], n;
pair<int,int> p[N];

int get(int l, int r){
    if(r < l) return 0;
    int &ret = dp[l][r];
    if(ret != -1) return ret;
    ret = 0;

    int i = l + (n - 1 - r);
    ret = max(ret,p[i].first * abs(l - p[i].second) + get(l+1,r));
    ret = max(ret, p[i].first * abs(r - p[i].second) + get(l,r-1));
    return ret;
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> p[i].first;
        p[i].second = i;
    }

    sort(p, p + n);
    reverse(p, p + n);
    memset(dp,-1,sizeof(dp));
    cout << get(0,n-1) << '\n';
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

