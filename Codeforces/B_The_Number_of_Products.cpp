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
    int prv_p = 0, prv_n = 0;
    int cur_p = 0, cur_n = 0;
    int cn = 0, cp = 0;

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x > 0){
            cur_p = prv_p + 1;
            cur_n = prv_n;
        }else{
            cur_p = prv_n;
            cur_n = prv_p + 1;
        }
        cn += cur_n;
        cp += cur_p;
        prv_p = cur_p, prv_n = cur_n;
    }
    cout<<cn<<' '<<cp<<endl;

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

