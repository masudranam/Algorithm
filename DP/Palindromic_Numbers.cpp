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

bool ok(int x){
    string t = to_string(x);
    for(int i = 0; i < sz(t)/2; i++){
        if(t[i] != t[sz(t)-i-1]) return false;
    }
    return true;
}

int dp[20][2][2];
string s;
int get(int idx,int small,int st, int cur){
    if(idx == sz(s)){
        if(ok(cur)){
            return 1;
        }
        return 0;
    }
    int &ret = dp[idx][small][st];
    if(ret != -1 && st) return ret;
    ret = 0;
    for(int i = 0; i <= (small?9:s[idx]-'0'); i++){
        ret += get(idx+1,small|((s[idx]-'0')>i),st|(i!=0),(cur*10+i));
    }
    return ret;
}

int get1(int x){
    if(x < 0)return 0;
    s = to_string(x);
    memset(dp,-1,sizeof(dp));
    return get(0,0,0,0);
}
void solve(){
    int a, b; 
    cin >> a >> b;
    if(a > b)swap(a,b);
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

