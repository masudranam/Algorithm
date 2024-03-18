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
    int n, m;
    cin >> n >> m;
    string s;

    int a[n+1][n+1][n+1];

    for(int i = 0; i <= n; i++)
    for(int j = 0; j <= n; j++)
    for(int k = 0; k <= n; k++){
        a[i][j][k] = 0;
    }

    for(int i = 0; i < m; i++){
        cin >> s;
        if(s == "UPDATE"){
            int x, y, z, w;
            cin >> x >> y >> z >> w;
            a[x][y][z] = w;
        }else{
            int x0, x1, y0, y1, z0, z1;
            cin >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
            int ans = 0;
            for(int x = x0; x <= x1; x++){
                for(int y = y0; y <= y1; y++){
                    for(int z = z0; z <= z1; z++){
                        ans += a[x][y][z];
                    }
                }
            }
            cout<<ans<<endl;
        }
    }
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

