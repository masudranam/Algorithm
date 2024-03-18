#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<endl
#define all(a) (a).begin(),(a).end()
#define sz(a) (int)(a.size())
#define int   long long int
#define endl '\n'
#define ar array
 
const int M = 1e9 - 100;
const int N = 2e5 + 10;


int get(int a, int b){
    int res = 0;
   // debug(a);debug(b);
   int cnt = 500;
    while(a % b  && cnt){
        a %= b;
        res += a;
        a <<= 1;
        cnt--;
    }
    if(cnt == 0)return -1;
    return res;
}

void solve(){

    int n, m;
    cin >> n >> m;
    int ans = get(n,m);
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

