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

bool isPrime(int x){
    for(int i = 2; i*i <= x; i++){
        if(x%i == 0)return false;
    }
    return true;
}

bool ok(int x, int y){
    int cnt = 0;
    while(x && y){
        cnt += (x%10 != y%10);
        x /= 10;
        y /= 10;
    }
    return (cnt == 1);
}

vector<int> g[N];

int bfs(int x, int y, int n){
    vector<int> vis(n+1),d(n+1,M);
    queue<int> q;
    q.push(x);
    vis[x] = 1, d[x] = 0;
    while(sz(q)){
        int u = q.front();
        q.pop();
        for(auto v: g[u]){
            if(!vis[v]){
                d[v] = d[u]+1;
                q.push(v);
                vis[v] = 1;
            }
        }
    }
    return d[y];
}

void solve(){

    vector<int> a;
    for(int i = 1000; i<= 9999; i++){
        if(isPrime(i))a.push_back(i);
    }

    int n = sz(a);
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(ok(a[i],a[j])){
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    
    map<int,int>mp;
    for(int i = 0; i < n; i++){
        mp[a[i]] = i;
    }

    int t; cin >> t;
    while(t--){
        int x, y;
        cin >> x >> y;
        x = mp[x], y = mp[y];
        cout<<bfs(x,y,n)<<endl;
    }
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

