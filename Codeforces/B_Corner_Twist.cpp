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
    vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c; cin >> c;
            a[i][j] = (int)(c-'0');
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
           char c; cin >> c;
           b[i][j] =(int)(c - '0');
        }
    }
 
    for(int i = 0; i + 1 < n; i++){
        for(int j = 0; j + 1 < m; j++){
            if(a[i][j] == b[i][j])continue;
            int d = b[i][j] - a[i][j];
            if(d < 0)d += 3;
            a[i][j] = b[i][j];
            a[i+1][j+1] = (a[i+1][j+1] + d)%3;
            a[i][j+1] = (a[i][j+1] + 2*d) % 3;
            a[i+1][j] = (a[i+1][j] + 2*d) % 3;
         }
    }

   
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] != b[i][j]){
                cout << "NO\n"; return;
            }
        }
    }
    cout << "YES\n";
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
