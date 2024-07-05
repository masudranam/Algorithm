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
    vector<vector<int>>a(n,vector<int>(m)), b(n,vector<int>(m));
    vector<int> row(n*m+1),col(n*m+1);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> b[i][j];
            row[b[i][j]] = i;
            col[b[i][j]] = j;
        }
    }

    for(int i = 0; i < n; i++){
        bool ok = 1;
        for(int j = 0; j < m; j++){
            ok &= (row[a[i][0]] == row[a[i][j]]);
        }
        if(!ok){
            cout << "NO\n";return;
        }
    }
    for(int j = 0; j < m; j++){
        bool ok = 1;
        for(int i = 0; i < n; i++){
            ok &= (col[a[0][j]] == col[a[i][j]]);
        }
        if(!ok){
            cout << "NO\n";
            return;
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
