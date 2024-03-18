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
const int N = 12 + 10;

int f[1<<N+1],a[1<<N];

void solve(){
    int n; cin >> n;
    memset(f,-1,sizeof(f));

    for(int i = 0; i < n; i++){
        cin >> a[i];
        f[a[i]^((1<<N)-1)] = a[i];
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < (1<<N ); j++){
            //debug((j|1));
            f[j] = max(f[j],f[j|(1<<i)]);
        }
    }
    for(int i = 0; i < n; i++){
        cout<<f[a[i]]<<' ';
    }

   


}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;  // cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

