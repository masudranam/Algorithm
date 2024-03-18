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

int n, p, k;
int a[105][10], cost[105];
map<int,map<vector<int>,int>>dp;    
int get(int pos,vector<int> cur,vector<int>target){
    if(pos == n){
        if(cur == target)return 0;
        else return M*N;
    }
    if(dp[pos].find(cur) != dp[pos].end())return dp[pos][cur];
    int ret = get(pos+1,cur,target);
    vector<int>nw;
    for(int i = 0; i < k;i++){
        nw.push_back(min(p,a[pos][i]+cur[i]));
    }
    ret = min(ret,get(pos+1,nw,target)+cost[pos]);
    return dp[pos][cur] = ret;
}


void solve(){
    cin >> n >> k >> p;

    for(int i = 0; i < n; i++){
        cin >> cost[i];
        for(int j = 0; j < k; j++){
            cin >> a[i][j];
        }
    }
    vector<int>t(k,p),t1(k,0);
    int val = get(0,t1,t);
    if(val >= N*M)cout<<-1<<endl;
    else cout<<val<<endl;

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

