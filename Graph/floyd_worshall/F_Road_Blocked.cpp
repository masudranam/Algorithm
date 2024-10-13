#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

struct edge{
    int u, v, w;
};

struct qry{
    int t, u, v;
};

void solve(){
    int n, m, q;
    cin >> n >> m >> q;
    edge e[m];
    vector<vector<int>> d(n + 1, vector<int>(n + 1, M * N));
    for(int i = 1; i <= n; i++)d[i][i] = 0;

    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        e[i] = {u, v, w};
        d[u][v] = min(d[u][v], w);
        d[v][u] = min(d[v][u], w);
    }  

    qry Q[q];
    for(int i = 0; i < q; i++){
        int t, u, v;
        cin >> t;
        if(t == 1){
            int id; cin >> id, id--;
            u = e[id].u, v = e[id].v;
            
            d[u][v] = M * N;
            d[v][u] = M * N;
            Q[i] = {t, id, 1};
        }else{
            cin >> u >> v;
            Q[i] = {t, u, v};
        }
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    auto upd = [&](int i){
        int u = e[i].u, v = e[i].v, w = e[i].w;
        d[u][v] = min(d[u][v], w);
        d[v][u] = min(d[v][u], w);

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                d[i][j] = min(d[i][j], d[i][u] + d[v][j] + w);
                d[i][j] = min(d[i][j], d[i][v] + d[u][j] + w);
            }
        }
    };

    vector<int> res(q);
    for(int i = q - 1; i >= 0; i--){
        if(Q[i].t == 1){
            upd(Q[i].u);
        }else{
            res[i] = d[Q[i].u][Q[i].v];
        }
    }

    for(int i = 0; i < q; i++){
        if(Q[i].t == 2){
            cout << (res[i] < N * M ? res[i]:-1) << '\n';
        }
    }


}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1; 
 //  cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}
