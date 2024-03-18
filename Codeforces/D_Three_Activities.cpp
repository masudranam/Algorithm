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
    int n; cin >> n;

    vector<int>a(n),b(n),c(n);

    for(auto &x : a) cin>> x;
    for(auto &x : b) cin >> x;
    for(auto &x : c) cin >> x;

    vector<ar<int,2>> x(n),y(n),z(n);

    for(int i = 0; i < n; i++){
        x[i] = {a[i],i};
        y[i] = {b[i],i};
        z[i] = {c[i],i};
    }

    sort(all(x)); sort(all(y)); sort(all(z));
    reverse(all(x)); reverse(all(y)); reverse(all(z));

    int ans = 0;

    for(int i = 0; i < min(n,8ll); i++){
        for(int j = 0; j < min(n,8ll); j++){
            for(int k = 0; k < min(n,8ll); k++){
                if(x[i][1] == y[j][1] || x[i][1] == z[k][1] || y[j][1] == z[k][1])continue;
                ans = max(ans,x[i][0] + y[j][0] + z[k][0]);
            }
        }
    }
    cout << ans << endl;
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

