#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

int dp[102][505][505];
int t, n;
vector<pair<int,int>> v;

int get(int i, int x, int y){
    if(x > t || y > t)return M;
    if(i == n){
        if(x == t && y == t)return 0;
        return M;
    }
    int &ret = dp[i][x][y];
    if(ret != -1) return ret;
    ret = get(i + 1, x, y) + (v[i].second != 3);
    ret = min(ret, get(i + 1, x + v[i].first, y) + (v[i].second != 1));
    ret = min(ret, get(i + 1, x, y + v[i].first) + (v[i].second != 2));
    return ret;
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        t += y;
        v.push_back({y, x});
    }

    if(t % 3){
        cout << -1 << '\n';return;
    }
    t /= 3;
    memset(dp, -1, sizeof(dp));
    int res = get(0, 0, 0);
    if(res < M){
        cout << res << '\n';
    }else{
        cout << - 1 << '\n';
    }

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1; 
   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}
