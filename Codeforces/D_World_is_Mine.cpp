#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 5e3 + 10;

vector<pair<int,int>> a;
int n, dp[N][N];

int get(int i, int ache){
    if(i == n) return 0;

    int &ret = dp[i][ache];
    if(ret != -1) return ret;

    ret = get(i+1,ache+1);
    if(a[i].second <= ache){
        ret = max(ret, get(i+1,ache - a[i].second) + 1);
    }
    return ret;
}

void solve(){
    cin >> n;
    map<int,int> mp;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        mp[x]++;
    }
    a.clear();
    for(auto it : mp){
        a.push_back({it.first, it.second});
    }
    n = a.size();
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            dp[i][j] = -1;
        }
    }
    
    cout << n - get(0,0) << '\n';
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
