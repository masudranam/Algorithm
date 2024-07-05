#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 1e3 + 10;

string s[N];
int d[N][N],t[N][N];
int vis[N][N],n, m;

bool ok(int i, int j){
   return (i < n && i >= 0 && j < m && j >= 0);
}

int dx[] = {0, 0, -1, 1};
int dy[] = {1,-1,  0, 0};
string path = "LRDU";


void solve(){
   cin >> n >> m;

   int si = 0, sj = 0;
   queue<pair<int,int>> q;
   memset(d,0x3f,sizeof(d));
   memset(t,0x3f,sizeof(t));   

   for(int i = 0; i < n; i++){
      cin >> s[i];
      for(int j = 0; j < m; j++){
         if(s[i][j] == 'A')si = i, sj = j;
         if(s[i][j] == 'M'){
            q.push({i,j});
            d[i][j] = 0;
         }
      }
   }


   while(q.size()){
      auto u = q.front();
    
      q.pop();
      for(int i = 0; i < 4; i++){
         int i1 = u.first + dx[i], j1 = u.second + dy[i]; 
         if(ok(i1,j1) && s[i1][j1] != '#' && d[i1][j1] > d[u.first][u.second] + 1){
            q.push({i1,j1});
            d[i1][j1] = d[u.first][u.second] + 1;
         }
      }
   }

   q.push({si,sj});
   t[si][sj] = 0;
   
   while(q.size()){
      auto u = q.front();
      q.pop();
    //cout << u.first << ' ' << u.second << '\n';
      if(u.first == n-1 || u.first == 0 || u.second == 0 || u.second == m-1){
            cout << "YES\n";
            string res = "";
            while(1){
               for(int i = 0; i < 4; i++){
                  int i1 = u.first + dx[i], j1 = u.second + dy[i];
                  if(ok(i1,j1) && t[i1][j1] + 1 == t[u.first][u.second]){
                     res += path[i];
                     u = {i1,j1};
                     break;
                  }
               }
               if(t[u.first][u.second] == 0)break;
            }
            reverse(res.begin(), res.end());
            cout << res.size() << '\n';
            cout << res << '\n';
            return;
      }
      for(int i = 0; i < 4; i++){
            int i1 = u.first + dx[i], j1 = u.second + dy[i];
            if(ok(i1,j1) && s[i1][j1] != '#' && d[i1][j1] > t[u.first][u.second] + 1 && t[i1][j1] > t[u.first][u.second] + 1){
               q.push({i1,j1});
               t[i1][j1] = t[u.first][u.second] + 1;
            }
         }
     }

   cout << "NO\n";

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
