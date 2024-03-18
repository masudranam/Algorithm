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
    string s[n];

    vector<vector<int>> a(n+1,vector<int>(n+1,0)),b(n+1,vector<int>(n+1,0));
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = n-1; j >= 0; j--){
            if(s[i][j] == 'o')a[i][j] = 1;
            a[i][j] += a[i][j+1];
        }
    }
    for(int j = 0; j < n; j++){
        for(int i = n-1;i >= 0; i--){
            if(s[i][j] == 'o')b[i][j] = 1;
            b[i][j] += b[i+1][j];
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(s[i][j] == 'x')continue;
            ans += (a[i][0]-1)*(b[0][j]-1);
        }
    }
    cout<<ans<<endl;
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

