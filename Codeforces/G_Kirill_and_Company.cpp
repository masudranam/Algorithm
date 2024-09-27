#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 1e4 + 10;

vector<int> g[N];
set<int> mask[N];
int n, m, k, f;
int h[N], p[10], d[N], carless[N], dp[N][65];

int get(int i, int msk){
    if(i == f){
        return __builtin_popcount(msk);
    }
    int &ret = dp[i][msk];
    if(ret != -1) return ret;
    ret = get(i + 1, msk);

    if(!carless[i]){
        for(auto x : mask[h[i]]){
            ret = max(ret, get(i+1, msk | x));
        }
    }
    return ret;
}

void solve(){
    cin >> n >> m; 

    for(int i = 0; i <= n; i++){
        g[i].clear(), mask[i].clear();
        d[i] = 0;
    } 

    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    cin >> f;
    for(int i = 0; i < f; i++){
        cin >> h[i], h[i]--;
    }

    for(int i = 0; i <= f; i++){
        for(int j = 0; j < 65; j++){
            dp[i][j] = -1;
        }
        carless[i] = 0;
    }

    cin >> k;
    for(int i = 0; i < k; i++){
        cin >> p[i], p[i]--;
        carless[p[i]] = 1;
        p[i] = h[p[i]];
    }

    queue<int> q;
    q.push(0);
    d[0] = 1;
    mask[0].insert(0);

    while(q.size()){
        int u = q.front();
        q.pop();
        int tmp = 0;
        for(int i = 0; i < k; i++){
            if(p[i] == u)tmp |= (1 << i);
        }

        set<int> st;
        for(auto s : mask[u]){
            st.insert(tmp | s);
        }
        mask[u] = st;

        for(auto v : g[u]){
            if(!d[v]){
                d[v] = d[u] + 1;
               q.push(v);
            }
            if(d[v] == d[u] + 1){
                for(auto s : mask[u]){
                    mask[v].insert(s);
                }
            }
        }
    }

    set<int> st;
    for(int i = 0; i < f; i++){
        if(!carless[i]){
            set<int> tmp;
            for(auto s : mask[h[i]]){
                for(auto s1 : st){
                    tmp.insert(s|s1);
                }
            }
            st = tmp;
        }

    }

    int ans = k;
    for(auto s : st){
        ans = min(ans,k - __builtin_popcount(s));
    }
    cout << ans << '\n';
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