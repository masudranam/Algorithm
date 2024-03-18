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
const int N = 5000 + 10;

vector<int> g[N];
int mx;
int n, k, a[N];
pair<int,int> dp[N];
int C[N][N];

pair<int,int> get(int i){
    if(i == n){
        return {0,1};
    }
    pair<int,int> &ret = dp[i];
    if(ret.first != -1)return ret;
    ret = get(i+1);
    int cur = 1;

    for(int j = i+1; j <n; j++){
        if(a[i] == a[j])cur++;
        if(cur >= k && a[i] == a[j]){
            auto p = get(j+1);
            p.first++;
            p.second = (p.second * C[cur-2][k-2]);
            if(p.first > ret.first){
                ret = p;
            }else if(ret.first == p.first){
                ret.second = (ret.second + p.second);
            }
        }
    }
    return ret;
}

void solve(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    if(k == 1){
        cout << 1 << endl;
        return;
    }

    memset(dp,-1,sizeof(dp));

    cout << get(0).second << endl;

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

    for(int i = 0; i < N; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0 || i == j)C[i][j] = 1;
            else{
                C[i][j] = (C[i-1][j] + C[i-1][j-1]) % M;
            }
        }
    }

   int t = 1;   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

