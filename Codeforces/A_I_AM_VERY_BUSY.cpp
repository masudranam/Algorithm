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
    vector<ar<int,2>> v;
    for(int i = 0; i < n; i++){
        int l, r; cin >> l >> r;
        v.push_back({r,l});
    }
    sort(all(v));
    int ans = 0, last = -M;
    for(int i = 0; i < n; i++){
        if(v[i][1] >= last){
            ans++;
            last = v[i][0];
        }
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

