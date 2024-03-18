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
int B, cost;

bool ok(int x){
    int a = x/2, b = x-x/2;
    int res = a*a + b*b + x*cost;
    return B >= res;
}
void solve(){
    cin >> B >> cost;

    int l = 0, r = 100;
    while(r-l > 0){
        int m = (l+r+1)/2;
        if(ok(m))l = m;
        else r = m-1;
    }
    cout<<(1ll<<l)<<endl;

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

