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


set<int> st[N];
int p[N];

int get(int x){
    if(p[x] == x) return x;
    return p[x] = get(p[x]);
}

void Merge(int u, int v){
   int u1 = p[u], v1 = p[v];

    if(sz(st[u1]) < sz(st[v1])){
        for(auto x: st[u1]){
            st[v1].insert(x);
        }
        st[u1].clear();
        p[u] = u;
        p[v] = v;  
    }else{
        for(auto x: st[v]){
            st[u].insert(x);
        }
        st[v].clear();
        p[v] = u;
        p[u] = v;
    }
}

void solve(){
    int n, q;
    cin >> n >> q;

    for(int i = 1; i <= n; i++){
        p[i] = i;
        int x; cin >> x;
        st[i].insert(x);
    }

    while(q--){
        int u, v;
        cin >> u >> v;
        Merge(u,v);
       // cout<<p[u]<<' '<<p[v]<<endl;
        cout<<sz(st[p[v]])<<endl;
    }
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

