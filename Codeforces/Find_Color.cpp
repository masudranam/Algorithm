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

void solve(){
    int x, y;
    cin >> x >> y;
    if(x == 0 || y == 0){
        cout<<"black\n";
        return;
    }
    if(x < 0 && y < 0)x = -x, y = -y;
    else if(x < 0 && y > 0) x = -x, y = -y;

    double d = x*x + y*y;
    
    d = sqrt(d);
    int cur = d;
   // cout<<d<<' '<<cur<<endl;
    if(y < 0){
        if(cur % 2 == 0 && cur != d)cout<<"white\n";
        else cout<<"black\n";
    }else {
        if(cur % 2 == 1 && cur != d)cout<<"white\n";
        else cout<<"black\n";
    }

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

