#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n; cin >> n;
    double d = 0;
    vector<pair<double, double>> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i].first >> a[i].second;
    }

    for(int i = 1; i <= n; i++){
        d = max(d, (i * 1.0) / a[i].second);
    }
   

    for(int i = 1; i <= n; i++){
        double cur = (i * 1.0) / d;
        if(cur >= a[i].first && cur <= a[i].second){
            continue;
        }
        cout << -1 << '\n';return;
    }
     
    cout << fixed << setprecision(6) << d << '\n';
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
   int t = 1; 
   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      cout<<"Case #"<<tc<<": ";
      solve();
   }
   return 0;
}
