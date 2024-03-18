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

int n, A, B;

string s;
int dp[42][42][42][42];

int get(int i, int a, int b, int x, int y){
    if(i == n){
        if(x + y > 0)return M;
        else return abs(a-b);
    }
    int &ret = dp[i][a][x][y];
    if(~ret)return ret;
    int d = s[ i ] - '0';
    ret = get(i+1,a+1,b,(x*10+d)%A,y);
    ret = min(ret,get(i+1,a,b+1,x,(y*10+d)%B));
    return ret;
}

void p(int i, int a, int b, int x, int y){
    if(i == n){
        cout<<'\n';
        return;
    }
   int ret = dp[i][a][x][y];
    int d = (s[i] - '0');

    if(ret == get(i+1,a+1,b,(x*10+d)%A,y)){
        cout<<'R'; p(i+1,a+1,b,(x*10+d)%A,y);
    }else{
        cout<<'B'; p(i+1,a,b+1,x,(y*10+d)%B);
    }

}

void solve(){
    cin >> n >> A >> B;
    cin >> s;
    memset(dp,-1,sizeof(dp));
    
    int ans = get(0,0,0,0,0);
    if(ans >= n)cout<<-1<<endl;
    else p(0,0,0,0,0);

    
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

