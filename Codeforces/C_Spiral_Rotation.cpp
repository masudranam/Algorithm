#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

void get(vector<vector<char>>& grid, int N) {
    for (int i = 1; i <= N / 2; ++i) {
        vector<vector<char>> tempGrid = grid;

        for (int x = i; x <= N + 1 - i; ++x) {
            for (int y = i; y <= N + 1 - i; ++y) {
                int targetX = y;
                int targetY = N + 1 - x;
                tempGrid[targetX - 1][targetY - 1] = grid[x - 1][y - 1];
            }
        }
        grid = tempGrid;
    }
}



void solve(){
    int n; cin >> n;
    vector<vector<char>> a(n, vector<char>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    get(a, n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << a[i][j];
        }
        cout << '\n';
    }
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1; 
   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}
