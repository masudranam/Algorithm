#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<endl
#define all(a) (a).begin(),(a).end()
#define sz(a) (int)(a.size())
#define int   long long int
#define endl '\n'
#define ar array
 
const double pi = acos(-1);
const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    double d, h, v, e;
    cin >> d >> h >> v >> e;

    double h1 = 0.25*pi*d*d;
    h1 = v/h1;
    

    if(e >= h1){
        cout<<"NO\n";
        return;
    }

    double l = 0, r = 100000;
    int cnt = 100;
    while(cnt--){
        double m = (l+r)/2;
        double x = m*(h1-e);
        if(x >= h)r = m;
        else l = m;
    }

    cout<<"YES\n";
    cout<<fixed<<setprecision(12)<<r<<endl;
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;  // cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

