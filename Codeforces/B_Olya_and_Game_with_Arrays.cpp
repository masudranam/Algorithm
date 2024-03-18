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
    int n;
    cin >> n;
    vector<int> a[n];
    int tot = 0,mn = M;
    for(int i = 0; i < n; i++){
        int m; cin >> m;
        while(m--){
            int x; cin >> x;
            a[i].push_back(x);
        }
        sort(all(a[i]));
        tot += a[i][1];
        mn = min(mn,a[i][0]);
    }

int ans = 0;
for(int i = 0; i < n; i++){
    ans = max(ans,tot-(a[i][1]-mn));
}

cout << ans << endl;


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

