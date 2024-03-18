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

void solve(){
    
    int n; cin >> n;
    string s[n+1];

    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
   
    int x0,y0,x1,y1;
    cin >> x0 >> y0 >> x1 >> y1;

    vector<vector<int>>vis(n+1,vector<int>(n+1,0));
    vector<vector<int>>d(n+1,vector<int>(n+1,0));

    vis[x0][y0] = 1;

    queue<ar<int,3>> q;
    q.push({x0,y0,0});

    while(sz(q)){
        ar<int,3> u = q.front();
        q.pop();
        d[u[0]][u[1]] = u[2];
        vis[u[0]][u[1]] = 1;
        for(int i = u[1]; i < n; i++){
            if(s[u[0]][i] == 'X')break;
            if(vis[u[0]][i])continue;
            vis[u[0]][i] = 1;
            q.push({u[0],i,u[2]+1});
        }

        for(int i = u[1]-1; i >= 0; i--){
           if(s[u[0]][i] == 'X')break;
            if(vis[u[0]][i])continue;
            vis[u[0]][i] = 1;
            q.push({u[0],i,u[2]+1}); 
        }

         for(int i = u[0]+1; i < n; i++){
           if(s[i][u[1]] == 'X')break;
            if(vis[i][u[1]])continue;
            vis[i][u[1]] = 1;
            q.push({i,u[1],u[2]+1}); 
        }

         for(int i = u[0]-1; i >= 0; i--){
           if(s[i][u[1]] == 'X')break;
            if(vis[i][u[1]])continue;
            vis[i][u[1]] = 1;
            q.push({i,u[1],u[2]+1}); 
        }  
    }

  cout<<d[x1][y1]<<endl;

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

