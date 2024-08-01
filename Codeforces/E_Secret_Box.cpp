#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int x, y, z, s;
    cin >> x >> y >> z >> s;

    int ans = 0;
    for(int i = 1; i <= x; i++){
        for(int j = 1; j <= y; j++){
            if(s % (i*j))continue;
            int k = s / (i * j);
            if(k > z)continue;
            ans = max(ans,(x - i + 1)*(y - j + 1)*(z - k + 1));
        }
    }
    cout << ans << '\n';
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

