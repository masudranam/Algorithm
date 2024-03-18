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
const int N = 5e5 + 10;

vector<int> g[N];
int dep[N],cnt,C[30];

vector<ar<int,2>>H[N];
int in[N],out[N],timer;
string s;

void dfs(int u, int p = -1, int d = 0){
   in[u] = ++timer;
   dep[u] = d;
   H[d].push_back({timer,(H[d].back()[1]^C[s[u]-'a'])});
    for(auto v: g[u]){
        dfs(v,u,d+1);
    }
    out[u] = ++timer;
}


void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i <= n; i++){
        H[i].resize(1);
    }

    for(int i = 1; i <n; i++){
        int p; cin >> p;
        p--;
        g[p].push_back(i);
    }
    for(int i = 0; i < 30; i++){
        C[i] = 1<<i;
    }

    cin >> s;
    dfs(0);

    for(int i = 0; i < m; i++){
        int v, h;
        cin >> v >> h;
        v--,h--;

        if(dep[v] >= h){
            cout <<"Yes\n";
            continue;
        }
        ar<int,2> x = {in[v],-1}, y = {out[v],-1};
        int l = lower_bound(all(H[h]),x)-H[h].begin()-1;
        int r = lower_bound(all(H[h]),y)-H[h].begin()-1;
        int t = H[h][l][1]^H[h][r][1];
        if(t&(t-1))cout<<"No\n";
        else cout<<"Yes\n";
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

