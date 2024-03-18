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

int n, k, x;

int get(int x, int n, int k){
    if(k < 0) return 0;
    int l = x, r = x;

    for(int i = 0; i <k; i++){
        l <<= 1;
        r <<= 1;
        r |= 1;
        if(l > n)return 0;
    }
    //debug(l);debug(r);
    return min(r,n)-l+1;
}

void solve(){
    int q; cin >> q;
    while(q--){
    cin >> n >> x >> k;

    int ans = get(x,n,k);
    while(x/2){
        k--;
        ans += get(x/2,n,k)-get(x,n,k-1);
        x /= 2;
     }
    cout<<ans<<endl;
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

