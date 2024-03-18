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
    int k; cin >> k;
    vector<int> a(n);
    int ans = M;
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
        for(int j = 0; j < 5;j++){
            if((a[i]+j)%k == 0)ans = min(ans,j);
        }
    }
    if(k == 4){
        ans = min(ans,2ll);
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(a[i]%2 == 0)cnt++;
        }
        if(cnt > 1)ans = 0;
        if(cnt == 1)ans = min(ans,1ll);
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

