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
const int N = 2e5 + 10;

int dp[5005][5005];
int a[5005];

int get(int l, int r ,int cur){
    if(l > r)return 0;
    if(l == r){
        return min(1ll,a[l]);
    }

    int ans = 0, mn = M, idx = l;

    for(int i = l; i <= r; i++){
       mn = min(mn,a[i]-cur);
    }

    for(int i = l; i <= r; i++){
        if(a[i] == cur + mn){
            ans += get(idx,i-1,cur+mn);
            idx = i+1;
        }
    }
    ans += get(idx,r,cur+mn);
    return min(r-l+1,ans+mn);
}

void solve(){
    int n; cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    memset(dp,-1,sizeof(dp));

    cout << get(0,n-1,0) << endl;

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

