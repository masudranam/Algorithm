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
    vector<vector<int>>a(n+1,vector<int>(n+1));
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    if(n == 1){
        cout<<"YES\n 0\n";return;
    }

    vector<int> ans(n+1);

    for(int i = 1; i <= n; i++){
        int cur = (1ll<<30)-1;
        for(int j = 1; j <= n; j++){
            if(i == j)continue;
            cur &= a[j][i];
        }
        ans[i] = cur;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j)continue;
            if((ans[i]|ans[j]) != a[i][j]){
                cout<<"NO\n";return;
            }
        }
    }
    cout<<"YES\n";
    for(int i = 1; i <= n; i++)cout<<ans[i]<<' ';cout<<endl;
    
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

