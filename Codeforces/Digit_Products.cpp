#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

int n, k;
string a;
unordered_map<int,int> dp[20][2];
int cnt;
int get(int i, int f, int p){
    
    if(i == (int)a.size()){
        return p != -1 && p <= k;
    }
    if(dp[i][f].find(p) != dp[i][f].end()){
        return dp[i][f][p];
    }
    int &ret = dp[i][f][p];
    ret = 0;
    for(int d = 0; d <= (f ? 9 : a[i] - '0'); d++){
        ret += get(i + 1, f || d < (a[i] - '0'), (p == -1 && d == 0 ? -1 : p == -1 ? d : p * d));
    }
    return ret;
}

void solve(){
    cin >> a >> k;
 
    cout << get(0, 0, -1) << '\n';
    cout << cnt << '\n';
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
