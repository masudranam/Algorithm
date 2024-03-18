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
    string s[n];
    for(int i = 0; i < n; i++)cin >> s[i];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == 0){
                if(j == 0)cout<<s[i+1][j];
                else cout<<s[i][j-1];
            }else if(i == n-1){
                if(j == n-1)cout<<s[i-1][n-1];
                else cout<<s[i][j+1];
            }else if(j == 0){
                if(i == n-1)cout<<s[n-1][1];
                else cout<<s[i+1][j];
            }else if(j == n-1){
                if(i == 0)cout<<s[0][n-2];
                else cout<<s[i-1][j];
            }else cout<<s[i][j];
        }
        cout<<endl;
    }

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

