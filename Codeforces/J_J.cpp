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
const int N = 500 + 10;

int di[] = {0,-1,0,1};
int dj[] = {1,0,-1,0};

int vis[N][N],a[N][N];
int n, m;

bool ok(int i, int j){
   return (i>=0 && i < n && j >= 0 && j < m);
}

int bfs(int i, int j){
   vis[i][j] = 1;
   queue<ar<int,2>> q;
   q.push({i,j});
   int cnt = 1,f = 0;
   vector<ar<int,2>> v;
   v.push_back({i,j});

   while(sz(q)){
      ar<int,2> t = q.front();
      q.pop();
      for(int idx = 0; idx < 4; idx++){
         i = di[idx]+t[0], j = dj[idx]+t[1];
         if(!ok(i,j))continue;
         if(a[i][j] < a[t[0]][t[1]])f = 1;

         if(!vis[i][j] && a[t[0]][t[1]] == a[i][j]){
            cnt++;
            vis[i][j] = 1;
            v.push_back({i,j});
            q.push({i,j});
         }
      }
   }
   if(f){
      for(auto t: v){
         vis[t[0]][t[1]] = 1;
      }
      return 0;
   }
   return cnt;
}

void solve(){

   cin >> n >> m;
   swap(n,m);

   for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
         cin >> a[i][j];
      }
   }

   int ans = 0;
   for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
         if(vis[i][j])continue;
        // cout<<i<<' '<<j<<' '<<bfs(i,j)<<endl;
         ans += bfs(i,j);
      }
   }
   cout<<ans<<endl;

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

