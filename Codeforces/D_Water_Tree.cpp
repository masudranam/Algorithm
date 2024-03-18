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
int in[N],out[N],tmr,p[N];
set<int> st;

void dfs(int u, int pr = 0){
    in[u] = ++tmr;
    p[u] = pr;
    int siz = 0;
    for(auto v: g[u]){
        if(pr == v)continue;
        siz++;
        dfs(v,u);
    }
    out[u] = ++tmr;
    if(siz == 0)st.insert(in[u]);
}

void solve(){

    int n; cin >> n;
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    dfs(1);
    cin >> n;
    
    while(n--){
        int t, v;
        cin >> t >> v;
        if(t == 1){
            if(p[v]){
                auto it = st.lower_bound(in[p[v]]);
                if(it != st.end() && *it <= out[p[v]]){
                    st.insert(in[p[v]]);
                }
            }
             st.erase(st.lower_bound(in[v]),st.upper_bound(out[v]));
        }else if(t == 2){
            st.insert(in[v]);
        }else{
            auto it = st.lower_bound(in[v]);
            if(it != st.end() && *it <= out[v]){
                cout<< 0 <<endl;
            }else cout<< 1 << endl;
        }
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

