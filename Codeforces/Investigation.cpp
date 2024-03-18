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

int dp[10][82][90][2];
string s;
int k;

int get(int idx, int sum, int rem,int small){
    if(k > 90)return 0;
    if(idx == sz(s)){
        if(sum % k == 0 && rem == 0)return 1;
        return 0;
    }
    int &ret = dp[idx][sum][rem][small];
    if(ret != -1)return ret;
    ret = 0;

    for(int dig = 0; dig <= (small?9:s[idx]-'0'); dig++){
        ret += get(idx+1,sum + dig,(rem*10+dig)%k,small|((s[idx]-'0')>dig));
    }
    return ret;
}
int get1(int x){
    s = to_string(x);
    memset(dp,-1,sizeof(dp));
    return get(0,0,0,0);
}
void solve(){
    int a, b;
    cin >> a >> b;
    cin >> k;
    cout<<get1(b)-get1(a-1)<<endl;

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
    cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

