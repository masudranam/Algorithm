#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

void solve(){
    int n, m;
    cin >> n >> m;
    string s[n];
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    if(s[0][0] == s[n-1][m-1] || s[0][m-1] == s[n-1][0]){
        cout << "YES\n";return;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(s[i][0] == s[0][j] && s[i][0] == s[n-1][m-1]){
                cout << "YES\n";return;
            }
            if(s[i][m-1] == s[0][j] && s[n-1][0] == s[i][m-1]){
                cout << "YES\n";return;
            }
            if(s[n-1][j] == s[i][m-1] && s[0][0] == s[n-1][j]){
                cout << "YES\n";return;
            }
            if(s[i][0] == s[n-1][j] && s[0][m-1] == s[i][0]){
                cout << "YES\n";return;
            }
        }
    }
    cout << "NO\n";
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

