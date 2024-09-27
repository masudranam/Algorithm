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
    vector<vector<int>>a(n,vector<int>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    int res = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int cur = 0;
            int l = i-1, r = j-1;
            while(l >= 0 && r >= 0){
                cur += a[l][r];
                l--,r--;
            }
            l = i-1, r = j+1;
            while(l >= 0 && r < m){
                cur += a[l][r];
                l--,r++;
            }
            l = i+1, r = j-1;
            while(l < n && r >= 0){
                cur += a[l][r];
                l++,r--;
            }
            l = i+1, r = j+1;
            while(l < n && r < m){
                cur += a[l][r];
                l++,r++;
            }
            cur += a[i][j];
            res = max(res, cur);
        }
    }
    cout << res << '\n';
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

