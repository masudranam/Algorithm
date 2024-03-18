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
    vector<ar<int,2>> a(n);
    for(int i = 0; i < n; i++){
        int x;cin >> x;
        a[i] = {x,i};
    }

    sort(all(a));
    vector<int> ans(n);
    for(int i = 0, j = n; i < n; i++,j--){
        ans[a[i][1]] = j;
    }
    print(ans);
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

