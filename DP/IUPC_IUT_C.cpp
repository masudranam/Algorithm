#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 3e3 + 10;

int n;
double dp[N][N];
pair<int,pair<int,int>>p[N];

double d(int i, int j){
   int x = p[i].second.first - p[j].second.first;
   int y = p[i].second.second - p[j].second.second;
   return sqrtl(x*x + y*y);
}

double get(int i, int j){
   if(i == n-2 || j == n-2){
      return d(i,n-1) + d(j,n-1);
   }

   if(dp[i][j] != -1.0) return dp[i][j];
   int k = max(i,j) + 1;
   double res = get(k,j) + d(i,k);
   res = min(res, get(i,k) + d(j,k));
   return dp[i][j] = res;
}

void solve(){
   cin >> n;
   for(int i = 0; i < n; i++){
      cin >> p[i].first;
      cin >> p[i].second.first;
      cin >> p[i].second.second;
   }
   sort(p, p + n);

   for(int i = 0; i <= n; i++){
      for(int j = 0; j <= n; j++){
         dp[i][j] = -1.0;
      }
   }
   cout << setprecision(5) << fixed;
   cout << get(0,0) << '\n';
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

