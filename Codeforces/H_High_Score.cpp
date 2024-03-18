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
const int N = 5e6 + 10;

vector<ar<int,3>> edges;

int belman(int n){
    vector<int> d(n+1,M*M);
    d[1] = 0;
    int flag = 0;
    for(int i = 1; i < n; i++){
         flag = -1;
        for(auto x: edges){
            if(d[x[0]] + x[2] < d[x[1]]){
                d[x[1]] = x[2]+d[x[0]];
                flag = 1;
            }
        }
    }
    if(flag == -1) return -d[n];
    return -1;
}



void solve(){

int n, m; cin >> n >> m;
int tot = 0;
for(int i = 0; i < m; i++){
    int u, v, w;
    cin >> u >> v >> w;
    edges.push_back({u,v,-w});
}


cout << belman(n) << endl;

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;  // cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

