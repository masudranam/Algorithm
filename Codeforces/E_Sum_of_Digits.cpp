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

int ans, n, k;

int dos(int x){
   int res = 0;
   while(x){
      res += (x%10);
      x /= 10;
   }
   return res;
}

void get(int x){
   int s = 0;
   if(x < 0)return;
   for(int i = x; i <= x+k; i++){
      s += dos(i);
   }
   if(s == n)ans = min(ans,x);
}


void solve(){
   cin >> n >> k;
   ans = M*M;

   for(int cur = 0; cur < M*M/10; cur = cur*10 + 9){
      for(int add = 0; add < 9; add++){
         int nw = (cur + 1)*add + cur;
         for(int i = nw - 18; i < nw + 19; i++){
            get(i);
         }
      }
   }
   if(ans == M*M)cout<<-1<<endl;
   else cout<<ans<<endl;

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

