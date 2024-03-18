#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<endl
#define all(a) (a).begin(),(a).end()
#define sz(a) (int)(a.size())
//#define int   long long int
#define endl '\n'
#define ar array
 
const int M = 1e9 + 7;
const int N = 5e5 + 10;

const int K = 700;
int a[N],b[K][K];

void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int t; cin >> t;
        if(t == 1){
            int x, y; cin >> x >> y;
            a[x] += y;
            for(int j = 1; j < K; j++)b[j][x%j] += y;
        }else{
            int x, y;
            cin >> x >> y;
            int res = 0;
            if(x < K)res = b[x][y];
            else {
                for(int j = y; j < N; j += x)res += a[j];
            }
            cout<<res<<endl;
        }
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



