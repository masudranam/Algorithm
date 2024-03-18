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
    int h, n;
    cin >> n >> h;

    vector<double> ans;
    double each = (0.5*h)/n;
    double cur = h;

    for(int i = 1; i < n; i++){
        double up = (n-i)*each;
        double l = 0, r = cur;
        int cnt = 100;
        while(cnt--){
            double h1 = (l+r)/2;
            double x = (h1/h)*.5*h1;
            if(x < up)l = h1;
            else r = h1;
        }
        cur = l;
        ans.push_back(l);
    }

    reverse(all(ans));

    for(auto x: ans){
        cout<<fixed<<setprecision(12)<<x<<endl;
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

