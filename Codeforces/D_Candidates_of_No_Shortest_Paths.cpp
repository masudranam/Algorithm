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

struct edge{
    int u, v, w;
};

void solve(){
    int n, m;
    cin >> n >> m;
    edge e[m];

    vector<vector<int>>d(n+1,vector<int>(n+1,M));

    for(int i = 0; i < m; i++){
        cin >> e[i].u >> e[i].v >> e[i].w;
        d[e[i].u][e[i].v] = d[e[i].v][e[i].u] = e[i].w;
    }
    for(int i = 1; i <= n; i++)d[i][i] = 0;

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }

    int ans = m;
    for(int i = 0; i < m; i++){
        int u = e[i].u, v = e[i].v, w = e[i].w;
        bool f = 0;
        for(int j = 1; j <= n; j++){
           if(d[j][u]+w == d[j][v])f = 1;
        }
        ans -= f;
    }
    cout << ans << endl;
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;  // cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

