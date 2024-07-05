#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 5000 + 10;

string s;
int n;
int dp[N][N];

int get(int i, int len){
    if(i == n) return 1;

    int &res = dp[i][len];
   // if(res != -1) return res;

    res = 0;
    int ok = 0, no = 0;
    for(int j = i, p = i - len; j < n; j++, p++){
        if(j+1 < n && s[j+1] == '0')continue;
        if(j - i + 1 > len) res = (res + get(j+1,j-i+1)) % M;
        if(j-i+1 == len){
            if(ok) res = (res + get(j+1,len)) % M;
        }
        if(no == false && s[j] > s[p]) ok = 1;
        if(s[p] > s[j])no = true;
    }
    return res;
}

void solve(){
    cin >> n;
    cin >> s;
    memset(dp,-1, sizeof(dp));

    int res = 0;
    for(int i = n; i > 0; i--){
       if(i+1 < n && s[i+1] == '0')continue;
       res = (res + get(i,i)) % M;
    }

    cout << res << '\n';
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
