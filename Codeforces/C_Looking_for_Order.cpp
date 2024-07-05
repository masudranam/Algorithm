#include<bits/stdc++.h>
using namespace std;

 
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

int x[50], y[50];
int dp[(1<<25)], n;

int d(int i, int j){
    return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
}

int get(int mask){
    if(!mask) return 0;
    if(dp[mask] != -1) return dp[mask];
    int i = 31 - __builtin_clz(mask);
    int res =  2*d(0,i) + get(mask^(1<<i));
    for(int j = 0; j < n; j++){
        if((mask>>j)&1){
            if(j != i){
                res = min(res,get(mask^(1<<i)^(1<<j)) + d(0,i)+d(i,j)+d(0,j));
            }
        }
    }
    return dp[mask] = res;
}

void print(int mask){
    if(!mask) return;
    int i = 31 - __builtin_clz(mask);
    if(get(mask) == get(mask^(1<<i)) + 2*d(0,i)){
        cout <<' '<< i << ' ' << 0 ;
        print(mask^(1<<i));
    }else{
        for(int j = 0; j < n; j++){
            if(mask&(1<<j)){
                if(i != j && get(mask) == get(mask^(1<<i)^(1<<j)) + d(0,i) + d(i,j)+d(0,j)){
                    cout <<' '<< i << ' ' << j << ' ' << 0 ;
                    print(mask^(1<<i)^(1<<j));
                    return;
                }
            }
        }
    }
}

void solve(){
    cin >> x[0] >> y[0];
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x[i] >> y[i];
    }

    memset(dp,-1,sizeof(dp));
    cout << get((1<<(n+1))-2) << '\n';
    cout << 0;
    print((1<<(n+1))-2);
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