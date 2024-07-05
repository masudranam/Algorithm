#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 6e3 + 10;

int dp[N][N];
pair<int,int> p[N];
int n,T;

int get(int i, int t){
    if(i == n){
        return 0;
    }
    int &ret = dp[i][t];
    if(~ret) return ret;

    ret = get(i+1,t);
    if(t < T){
        ret = max(ret, p[i].second + get(i+1,p[i].first + t));
    }
    return ret;
}


void solve(){
    cin >> n;
    cin >> T;

    for(int i = 0; i < n; i++){
        cin >> p[i].first >> p[i].second;
    }
    sort(p,p+n);

    memset(dp,-1,sizeof(dp));

    cout << get(0,0) << '\n';
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
