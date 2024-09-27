#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

int dp[35][35][52], k;
int b[N];
vector<int> a;

int get(int i, int p, int cur){
    if(cur > k) return M;
    if(i == a.size()){
        return 0;
    }
    int &ret = dp[i][p][cur];
    if(ret != -1) return ret;
    ret = M;

    for(int j = 0; j <= 30; j++){
        ret = min(ret, get(i + 1, j, min(k + 5,cur + abs(j - p))) + abs(a[i] - j));
    }    
    return ret;
}

vector<int> get1(int l, int r){
    vector<int> c;
    for(int i = l; i <= r; i++){
        if(c.empty() || c.back() != b[i])
        c.push_back(b[i]);
    }
    return c;
}

void solve(){
    int n, q;
    cin >> n >> q;

    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }

    while(q--){
        int l, r;
        cin >> l >> r >> k;
        a = get1(l,r);

        for(int i = 0; i <= (int)a.size(); i++){
            for(int j = 0; j <= 32; j++){
                for(int l = 0; l <= 50; l++){
                    dp[i][j][l] = -1;
                }
            }
        }

        if(a.size() == 1){
            cout << 0 << '\n';
            continue;
        }
        int res = M;
        for(int i = 0; i <= 30; i++){
            res = min(res, get(1,i,0) + abs(a[0] - i));
        }
        cout << res << '\n';
    }
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}
