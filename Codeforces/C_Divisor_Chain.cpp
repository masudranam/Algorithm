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

void solve(){
    int n; cin >> n;
    vector<int> ans;
    ans.push_back(n);

    for(int i = 0; i < 33; i++){
        if(n&(1ll<<i)){
            if(n > (1ll<<i)){
                n -= (1ll<<i);
                ans.push_back(n);
            }
        }
    }
    while(n > 1){
        ans.push_back(n/2);
        n /= 2;
    }
    cout<<sz(ans)<<endl;
    print(ans);

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

