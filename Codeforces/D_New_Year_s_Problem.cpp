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
    int m; cin >> m;

    vector<int> mx(m);
    int ans = 0;

    for(int i = 0; i < n; i++){
        vector<int> p(m);
        for(int j = 0; j < m; j++){
            cin >> p[j];
            mx[j] = max(mx[j],p[j]);
        }
        sort(all(p));
        ans = max(ans,p[m-2]);
    }

    for(int i = 0; i < m; i++){
        ans =min(ans,mx[i]);
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

