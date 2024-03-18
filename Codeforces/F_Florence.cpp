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

int get(int t, int i){
    int d = (i*(100.0+t))/100;
    return d;
}

void solve(){
   int t, n;
   cin >> t >> n;
   int x = INT_MAX-1000;
   int l = 1, r = x*x/100;

   while(r-l> 0){
    int m = (l+r)/2;
    if(get(t,m)-m >= n)r = m;
    else l = m+1;
   }
   cout<<get(t,l)-1<<endl;
  
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

