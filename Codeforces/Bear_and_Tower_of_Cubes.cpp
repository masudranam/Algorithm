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

int n; 
int f(int x){
    return x*x*x;
}
map<int,pair<int,int>>dp;

pair<int,int> get(int x){
    
    if(x <= 7)return {x,x};
    if(dp.find(x) != dp.end()) return dp[x];

    int l = 1, r = N, m;
    while(r-l>0){
         m = (l+r+1)/2;
        if(m*m*m <= x)l = m;
        else r = m-1;
    }

    m = l;
    pair<int,int> res = get(x-f(m));
    res.first++;
    res.second += m*m*m;
    
    pair<int,int> tmp = get(f(m)-1-f(m-1));
    tmp.second += f(m-1);
    tmp.first ++;
    return dp[x] = max(res,tmp);
}

void solve(){
    cin >> n;
    pair<int,int> res = get(n);
    cout<<res.first<<' '<<res.second<<endl;
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

