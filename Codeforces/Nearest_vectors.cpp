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
#define double long double
const double pi = acos(-1);


void solve(){
    int n; cin >> n;
    vector<pair<double,int>>a(n);

    for(int i = 0; i < n; i++){
        double x, y;
        cin >> x >> y;
        a[i] = {atan2(y,x),i};
    }

    sort(all(a));
    a.push_back(a[0]);

    double ans = 2*pi;
    int f = -1, s = -1;
    for(int i = 0; i < n; i++){
        double df = a[i+1].first - a[i].first;
        if(df < 0) df += 2*pi;
        if(ans > df){
            ans = df;
            f = a[i].second, s = a[i+1].second;
        }
    }

    cout<<f+1<<' '<<s+1<<endl;
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

