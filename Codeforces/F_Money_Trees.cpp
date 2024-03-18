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

int a[N],h[N],ps[N],d[N];
int n, k;

bool ok(int x){
    for(int i = x; i <= n; i++){
      if((d[i]-d[i-x+1] == x-1) && (ps[i]-ps[i-x]) <= k)
      return true;
    }
    return false;
}

void solve(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        ps[i] = ps[i-1]+a[i];
    }

    for(int i = 1; i <= n; i++){
        cin >> h[i];
        if(h[i-1]%h[i] == 0)d[i] = 1;
        else d[i] = 0;
        d[i] = d[i-1]+d[i];
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] <= k)ans = 1;
    }
    if(ans == 0){
        cout<<ans<<endl;
        return;
    }
    int l = 1, r = n;
    while(r-l > 0){
        int m = (l+r+1)/2;
        if(ok(m))l = m;
        else r = m-1;
    }
    ans = max(ans,l);
    cout<<ans<<endl;

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

