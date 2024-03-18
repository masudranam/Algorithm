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

int get(int l, int r){
    return (l+r)*(r-l+1)/2;
}

int lcm(int x, int y){
    return (x/__gcd(x,y))*y;
}
void solve(){
    int n, x, y;
    cin >> n >> x >>y;
    int l = lcm(x,y);
    int a = n/x, b = n/y, c = n/l;
    a -= c, b -= c;
//  debug(a);debug(b);debug(c);
    int f = get(n-a+1,n), sc = get(1,b);
    // debug(f);debug(sc);
    cout<<f-sc<<endl;


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

