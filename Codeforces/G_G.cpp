#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<endl
#define all(a) (a).begin(),(a).end()
#define sz(a) (int)(a.size())
#define int   long long int
#define endl '\n'
#define ar array
#define dbl long double
 
const int M = 1e9 + 7;
const int N = 3e6 + 10;

int n; 
dbl h;
dbl area;

dbl get(dbl prev_h, dbl cur_h){
   dbl height = cur_h-prev_h;
   dbl cur_base = (1.0/h)*(h-cur_h);

   dbl res = cur_base*height;
   dbl prev_base = (1.0/h)*(h-prev_h);
   dbl t_base = (prev_base-cur_base)/2.0;
   res = res + 2*t_base*height;

   return res;
}


void solve(){ 
   cin >> n >> h;

   area = (0.5*h)/(1.0*n);
   dbl prev_h = 0;
  debug(get(0,70710));

   for(int i = 1; i < n; i++){
      dbl l = prev_h, r = h;

      while(r-l > 0.000001){
         dbl m = (r+l)/2.0;
         dbl cur = get(prev_h,m);
         //debug(cur);
         if(cur > area)r = m;
         else l = m;
        // debug(l);
      }

      prev_h = l;
      cout<<l<<' ';
   }
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;  
    //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

