#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e3 + 100;

int dp[110][N];
struct data{
    int t, d, p, id;
    bool operator <(const data &other)const{
        return t + d < other.t + other.d;
    }
};

void solve(){
    int n, 
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1; 
//   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}
