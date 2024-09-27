#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 3e3 + 10;
const int Inf = 0x3f3f3f3f3f3f3f3f;

const int S = 3, E = 4, wall = 1, hammer = 2, L = 1, R = 2;
inline void mn(int &x, int y){x = min(x, y);}

struct node{
    int pos, id, type;
    bool operator < (const node &a)const{
        return pos < a.pos;
    }
};
vector<node> a;

int vis[N], n, x;
int dp[N][N][3], ok[N][N][3];

int get(int l, int r, int d){
    if(ok[l][r][d])return dp[l][r][d];
    ok[l][r][d] = 1;

    int pos = (d == L ? a[l].pos : a[r].pos);
    if(r + 1 < n){
        if(a[r + 1].type == wall && vis[a[r + 1].id]){
            mn(dp[l][r][d], get(l, r + 1, R) + a[r + 1].pos - pos);
        }
        if(a[r + 1].type == hammer){
            vis[a[r + 1].id] = 1;
            mn(dp[l][r][d], get(l, r + 1, R) + a[r + 1].pos - pos);
            vis[a[r + 1].id] = 0;
        }
        if(a[r + 1].type == E){
            mn(dp[l][r][d], a[r + 1].pos - pos);
        }
    }

    if(l - 1 >= 0){
        if(a[l - 1].type == wall && vis[a[l - 1].id]){
            mn(dp[l][r][d], get(l - 1, r, L) + pos - a[l - 1].pos);
        }
        if(a[l - 1].type == hammer){
            vis[a[l - 1].id] = 1;
            mn(dp[l][r][d], get(l - 1, r , L) + pos - a[l - 1].pos);
            vis[a[l - 1].id] = 0;
        }
        if(a[l - 1].type == E){
            mn(dp[l][r][d], pos - a[l - 1].pos);
        }
    }
    return dp[l][r][d];
}

void solve(){
    cin >> n >> x;
    for(int i = 1; i <= n; i++){
        int val; cin >> val;
        a.push_back({val, i, wall});
    }
    for(int i = 1; i <= n; i++){
        int val; cin >> val;
        a.push_back({val, i, hammer});
    }

    a.push_back({0, 0, S}); a.push_back({x, 0, E});
    sort(a.begin(), a.end());
    memset(dp, 0x3f, sizeof(dp));
    n = 2 * (n + 1);
    
    //cout << dp[0][0][0] << '\n';
    //cout << M * M * 4 << '\n';

    for(int i = 0; i < n; i++){
        if(a[i].type == S){
            int res = get(i, i, L);
            if(res == Inf)res = -1;
            cout << res << '\n';
            return;
        }
    }
    cout << - 1 << '\n';
    
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
