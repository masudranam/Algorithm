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
    int n, m;
    cin >> n >> m;

    vector<ar<int,2>> a(n);
    int mn = M;

    for(int i = 0; i < n; i++){
        cin >> a[i][0] >> a[i][1];
        mn = min(a[i][1]-a[i][0]+1, mn);
    }

    sort(all(a));

    int ans = 0, left = M;

    for(int i = 0; i < n; i++){
        int l = a[i][0], r = a[i][1];
        l = max(l,left+1);
        int len = min(m,r-l+1);
        ans = max(ans,2*len);
        left = min(left,a[i][1]);

        l = a[i][0], r = min(a[i][1],a[n-1][0]-1);
        len = min(m,r-l+1);
        ans = max(ans,2*len);
        len = min(m,a[i][1]-a[i][0]+1);
        ans = max(ans,2*(len-mn));
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

