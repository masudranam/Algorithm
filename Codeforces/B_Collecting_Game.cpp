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
        cin >> a[i][0];
        a[i][1] = i;
    }

    int cur = 0;

    sort(all(a));
  

    vector<int> ans(n),pf(n);
    for(int i = 0; i < n; i++){
        pf[i] = a[i][0];
        if(i)pf[i] += pf[i-1];
    }
    ans[a[n-1][1]] = n-1;

    for(int i = n-2; i >= 0; i--){
        if(a[i+1][0] > pf[i])ans[a[i][1]] = i;
        else ans[a[i][1]] = ans[a[i+1][1]];
    }

    for(int i = n-2; i >= 0; i--){
        ans[a[i][1]] = min(ans[a[i][1]],ans[a[i+1][1]]);
    }

    for(int i = 0; i < n; i++)cout<<ans[i]<<' ';
    cout<<endl;
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

