#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<endl
#define all(a) (a).begin(),(a).end()
#define sz(a) (int)(a.size())
//#define int   long long int
#define endl '\n'
#define ar array
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

int sum , cnt;
int f(int x){
    return x*x*x;
}

void get(int m, int step, int cur){
    if(step > cnt || (cnt == step && cur > sum)){
        cnt = step, sum = cur;
    }
    int a = cbrt(m);
    if(a > 0)get(m - f(a),step+1,cur+f(a));
    if(a > 1)get(f(a)-1-f(a-1),step+1,cur+f(a-1));
}

void solve(){
    int m; cin >> m;
    get(m,0,0);
    cout<<cnt<<' '<<sum<<endl;
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

