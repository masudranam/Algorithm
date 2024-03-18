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
const int N = 3e7 + 10;

bool vis[N];
int cnt[25];
int n, m;

void ok(){
    int cur = 0;
    for(int i = 1; i <= 23; i++){
        for(int j = 1; j <= m; j++){
            if(!vis[i*j]){
                cur++;
                vis[i*j] = 1;
            }
        }
        cnt[i] = cur;
    }
}

void solve(){
  cin >> n >> m;

  ok();
  for(int i = 0; i <= n; i++){
    vis[i] = 0;
  }

  int ans = 1;
  for(int i = 2; i <= n; i++){
    int x = i, cur = 0;
    if(vis[i])continue;
    while(x <= n){
        cur++;
        vis[x] = 1;
        x*=i;
    }
    ans += cnt[cur];
  }

  cout << ans << endl;
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

