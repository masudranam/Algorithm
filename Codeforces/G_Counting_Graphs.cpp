#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<endl
#define all(a) (a).begin(),(a).end()
#define sz(a) (int)(a.size())
#define int   long long int
#define endl '\n'
#define ar array
 
const int M = 998244353; //1e9 + 7;
const int N = 2e5 + 10;

int p[N],siz[N];

int get(int v) {
    return v==p[v]?v:p[v]=get(p[v]);
}

void Merge(int a,int b) {
        if(siz[a]<siz[b])swap(a,b);
        p[b]=a;
        siz[a]+=siz[b];
}

int pw(int a, int b){
    int res = 1;
    while(b){
        if(b&1)res = (res*a)%M;
        a = (a*a) % M;
        b >>= 1;
    }
    return res;
}

void solve(){
int n, s;
cin >> n >> s;
for(int i = 0; i <= n; i++){
    p[i] = i, siz[i] = 1;
}

vector<ar<int,3>> edges;

for(int i = 1; i < n; i++){
    int u, v, w;
    cin >> u >> v >> w;
    edges.push_back({w,u,v});
}

sort(all(edges));

int ans = 1;

for(int i = 0; i <n-1; i++){
    int u = get(edges[i][1]),v = get(edges[i][2]);
    int choices = (s-edges[i][0]+1);
    int edge = siz[u]*siz[v]-1;
    ans = (ans*pw(choices,edge))%M;
    Merge(u,v);
}


cout << ans << endl;
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

