#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 5e3 + 10;
int a[N], c[N], dp[N][N], n;
vector<int> b;


struct ST{
    int n;
    const int LOG = 22;
    vector<int> a,pw;
    vector<vector<int>>mx,mn;

    ST(vector<int> _a){
        a = _a; n = (int)a.size();  pw = vector<int>(n+10);
        mx = mn = vector<vector<int>>(n+1,vector<int>(LOG+1));

        pw[1] = 0;
        for(int i = 2; i <= n; i++){
            pw[i] = pw[i/2] + 1;
        }
        for(int i = 0; i < n; i++){
            mx[i][0] = mn[i][0] = a[i];
        }

        for(int k = 1; k < LOG; k++){
            for(int i = 0; (i+(1<<k)-1) < n; i++){
                mx[i][k] = max(mx[i][k-1],mx[i+(1<<(k-1))][k-1]);
                mn[i][k] = min(mn[i][k-1],mn[i+(1<<(k-1))][k-1]);
            }
        }
    }
    
        int qmx(int l, int r){
            int k = pw[r-l+1];
            return max(mx[l][k],mx[r-(1<<k)+1][k]);            
        }
        int qmn(int l, int r){
            int k = pw[r-l+1];
            return min(mn[l][k],mn[r-(1<<k)+1][k]);
        }
};

int get(int i, int j, ST &st){
    if(i == n) return 0;
    int &ret = dp[i][j];
    if(ret != -1) return dp[i][j];
    ret = get(i + 1, j, st) + a[i] + st.qmn(j,i);
    if(!c[i]) ret = min(ret, get(i + 1, j + 1, st));
    return ret;
}

void solve(){
    int  m;
    cin >> n >> m;
    b.assign(n,0);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    for(int i = 0; i < m; i++){
        int x; cin >> x, x--;
        c[x] = 1;
    }

    ST st(b);
    memset(dp, -1, sizeof(dp));

    cout << get(0, 0, st) << '\n';
 
  
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1; 
//   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}
